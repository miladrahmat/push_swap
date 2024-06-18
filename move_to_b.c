/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:31:08 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/18 16:15:49 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_small_b(t_vec *a, t_vec *b, t_sort *info)
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
	if (info->above_median_a)
		while (info->index_a-- > 0)
			ra(a, false);
	else
		while (info->index_a-- > 0)
			rra(a, false);
	if (info->above_median_b)
		while (info->index_a-- > 0)
			rb(b, false);
	else
		while (info->index_b-- > 0)
			rrb(b, false);
	pb(a, b);
}

static void	push_large_b(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->above_median_a && info->above_median_b)
		while (info->index_b-- > 0)
		{
			rr(a, b);
			info->index_a--;
		}
	else if (!info->above_median_a && !info->above_median_b)
		while (info->index_b-- > 0)
		{
			rrr(a, b);
			info->index_a--;
		}
	if (info->above_median_a)
		while (info->index_a-- > 0)
			ra(a, false);
	else
		while (info->index_a-- > 0)
			rra(a, false);
	if (info->above_median_b)
		while (info->index_b-- > 0)
			rb(b, false);
	else
		while (info->index_b-- > 0)
			rrb(b, false);
	pb(a, b);
}

static void	push_equal_b(t_vec *a, t_vec *b, t_sort *info)
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
	if (info->above_median_a)
		while (info->index_a-- > 0)
			ra(a, false);
	else
		while (info->index_a-- > 0)
			rra(a, false);
	if (info->above_median_b)
		while (info->index_b-- > 0)
			rb(b, false);
	else
		while (info->index_b-- > 0)
			rrb(b, false);
	pb(a, b);
}

void	move_to_b(t_vec *a, t_vec *b, t_sort *info)
{
	if (info->push_cost_a > info->push_cost_b)
		push_small_b(a, b, info);
	else if (info->push_cost_a < info->push_cost_b)
		push_large_b(a, b, info);
	else if (info->push_cost_a == info->push_cost_b)
		push_equal_b(a, b, info);
}
