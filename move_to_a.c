/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:19:57 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/19 13:57:50 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	rotate_a(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->push_cost_a > info->push_cost_b)
	{
		while (info->push_cost_b-- > 0)
		{
			rr(a, b);
			info->push_cost_a--;
		}
		while (info->push_cost_a-- > 0)
			ra(a, false);
	}
	else if (info->push_cost_a < info->push_cost_b)
	{
		while (info->push_cost_a-- > 0)
		{
			rr(a, b);
			info->push_cost_b--;
		}
		while (info->push_cost_b-- > 0)
			rb(a, false);
	}
	else if (info->push_cost_a == info->push_cost_b)
		while (info->push_cost_a-- > 0 && info->push_cost_b-- > 0)
			rr(a, b);
	pa(a, b);
}

static void	rev_rotate_a(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->push_cost_a > info->push_cost_b)
	{
		while (info->push_cost_b-- > 0)
		{
			rrr(a, b);
			info->push_cost_a--;
		}
		while (info->push_cost_a-- > 0)
			rra(a, false);
	}
	else if (info->push_cost_a < info->push_cost_b)
	{
		while (info->push_cost_a-- > 0)
		{
			rrr(a, b);
			info->push_cost_b--;
		}
		while (info->push_cost_b-- > 0)
			rrb(a, false);
	}
	else if (info->push_cost_a == info->push_cost_b)
		while (info->push_cost_a-- > 0 && info->push_cost_b-- > 0)
			rrr(a, b);
	pa(a, b);
}

static void	mix_rotate_a(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->above_median_a == true && info->above_median_b == false)
	{
		while (info->push_cost_a-- > 0)
			ra(a, false);
		while (info->push_cost_b-- > 0)
			rrb(b, false);
		pa(a, b);
	}
	else if (info->above_median_a == false && info->above_median_b == true)
	{
		while (info->push_cost_a-- > 0)
			rra(a, false);
		while (info->push_cost_b-- > 0)
			rb(b, false);
		pa(a, b);
	}
}

void	move_to_a(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->above_median_a == true && info->above_median_b == true)
		rotate_a(a, b, info);
	else if (info->above_median_a == false && info->above_median_b == false)
		rev_rotate_a(a, b, info);
	else
		mix_rotate_a(a, b, info);
}

void	sort_rest(t_vec *a)
{
	if (find_biggest_ind(a) <= (a->len - 1) / 2)
		while (is_sorted(a) < 0)
			ra(a, false);
	else
		while (is_sorted(a) < 0)
			rra(a, false);
}
