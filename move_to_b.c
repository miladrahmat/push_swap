/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- < mrahmat-@student.hive.fi >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:31:08 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/21 17:41:08 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_b(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->push_cost_a > info->push_cost_b)
	{
		while (info->push_cost_b-- > 0)
		{
			rr(a, b, false);
			info->push_cost_a--;
		}
		while (info->push_cost_a-- > 0)
			ra(a, false);
	}
	else if (info->push_cost_a < info->push_cost_b)
	{
		while (info->push_cost_a-- > 0)
		{
			rr(a, b, false);
			info->push_cost_b--;
		}
		while (info->push_cost_b-- > 0)
			rb(b, false);
	}
	else if (info->push_cost_a == info->push_cost_b)
		while (info->push_cost_a-- > 0 && info->push_cost_b-- > 0)
			rr(a, b, false);
	pb(a, b, false);
}

static void	rev_rotate_b(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->push_cost_a > info->push_cost_b)
	{
		while (info->push_cost_b-- > 0)
		{
			rrr(a, b, false);
			info->push_cost_a--;
		}
		while (info->push_cost_a-- > 0)
			rra(a, false);
	}
	else if (info->push_cost_a < info->push_cost_b)
	{
		while (info->push_cost_a-- > 0)
		{
			rrr(a, b, false);
			info->push_cost_b--;
		}
		while (info->push_cost_b-- > 0)
			rrb(b, false);
	}
	else if (info->push_cost_a == info->push_cost_b)
		while (info->push_cost_a-- > 0 && info->push_cost_b-- > 0)
			rrr(a, b, false);
	pb(a, b, false);
}

static void	mix_rotate_b(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->above_median_a == true && info->above_median_b == false)
	{
		while (info->push_cost_a-- > 0)
			ra(a, false);
		while (info->push_cost_b-- > 0)
			rrb(b, false);
	}
	else if (info->above_median_a == false && info->above_median_b == true)
	{
		while (info->push_cost_a-- > 0)
			rra(a, false);
		while (info->push_cost_b-- > 0)
			rb(b, false);
	}
	pb(a, b, false);
}

void	move_to_b(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->above_median_a == true && info->above_median_b == true)
		rotate_b(a, b, info);
	else if (info->above_median_a == false && info->above_median_b == false)
		rev_rotate_b(a, b, info);
	else
		mix_rotate_b(a, b, info);
}
