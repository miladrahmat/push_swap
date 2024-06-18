/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:19:57 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/18 18:06:52 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	rotate_a(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->push_cost_a > info->push_cost_b)
	{
		while (info->push_cost_b > 0)
		{
			rr(a, b);
			info->push_cost_b--;
			info->push_cost_a--;
		}
		while (info->push_cost_a > 0)
		{
			ra(a, false);
			info->push_cost_a--;
		}
	}
	else if (info->push_cost_a < info->push_cost_b)
	{
		while (info->push_cost_a > 0)
		{
			rr(a, b);
			info->push_cost_b--;
			info->push_cost_a--;
		}
		while (info->push_cost_b > 0)
		{
			rb(a, false);
			info->push_cost_a--;
		}
	}
	else if (info->push_cost_a == info->push_cost_b)
		while (info->push_cost_a > 0 && info->push_cost_b > 0)
		{
			rr(a, b);
			info->push_cost_a--;
			info->push_cost_b--;
		}
	pa(a, b);
}

static void	rev_rotate_a(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->push_cost_a > info->push_cost_b)
	{
		while (info->push_cost_b > 0)
		{
			rrr(a, b);
			info->push_cost_b--;
			info->push_cost_a--;
		}
		while (info->push_cost_a > 0)
		{
			rra(a, false);
			info->push_cost_a--;
		}
	}
	else if (info->push_cost_a < info->push_cost_b)
	{
		while (info->push_cost_a > 0)
		{
			rrr(a, b);
			info->push_cost_b--;
			info->push_cost_a--;
		}
		while (info->push_cost_b > 0)
		{
			rrb(a, false);
			info->push_cost_a--;
		}
	}
	else if (info->push_cost_a == info->push_cost_b)
		while (info->push_cost_a > 0 && info->push_cost_b > 0)
		{
			rrr(a, b);
			info->push_cost_a--;
			info->push_cost_b--;
		}
	pa(a, b);
}

/* static void	push_equal_a(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->above_median_a && info->above_median_b)
		while (info->index_a-- > 0)
		{
			rr(a, b);
			info->index_b--;
		}
	else if (!info->above_median_a && !info->above_median_b)
		while (info->index_a-- > 0)
		{
			rrr(a, b);
			info->index_b--;
		}
	pa(a, b);
} */

void	move_to_a(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->above_median_a == true && info->above_median_b == true)
		rotate_a(a, b, info);
	if (info->above_median_a == false && info->above_median_b == false)
		rev_rotate_a(a, b, info);
	if (info->push_cost_a == true && info->push_cost_b == false)
	{
		while (info->push_cost_a > 0)
		{
			ra(a, false);
			info->push_cost_a--;
		}
		while (info->push_cost_b > 0)
		{
			rrb(b, false);
			info->push_cost_b--;
		}
	}
	if (info->push_cost_a == false && info->push_cost_b == true)
	{
		while (info->push_cost_a > 0)
		{
			rra(a, false);
			info->push_cost_a--;
		}
		while (info->push_cost_b > 0)
		{
			rb(b, false);
			info->push_cost_b--;
		}
	}
}

void	sort_rest(t_vec *a)
{
	if (find_biggest_ind(a) < (a->len - 1) / 2)
		while (is_sorted(a) < 0)
			ra(a, false);
	else
		while(is_sorted(a) < 0)
			rra(a, false);
}
