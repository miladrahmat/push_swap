/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:31:08 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/17 17:30:16 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_vec *a, t_vec *b, t_sort *info)
{
	info->index = get_cheapest(b, info);
	if (info->index->above_median && info->index->target_index->above_median)
	{
		if (info->index != info->index->target_index)
		{
			while (info->index-- > info->index->target_index)
				rb(b, false);
			while (info->index < info->index->target_index--)
				ra(a, false);
		}
		if (info->index == info->index->target_index)
			while (info->index-- > 0 && info->index->target_index-- > 0)
				rr(a, b);
	}
	else if (!info->index->above_median && \
				!info->index->target_index->above_median)
	{
		if (info->index != info->index->target_index)
		{
			while (info->index > info->index->target_index++)
				rra(b, false);
			while (info->index++ < info->index->target_index)
				rrb(a, false);
		}
		if (info->index == info->index->target_index)
			while (info->index++ > b->len - 1 && \
				info->index->target_index++ > a->len - 1)
				rrr(a, b);
	}
	if (info->index == 0 && info->index->target_index == 0)
		pb(a, b);
}

size_t	get_cheapest(t_vec *vec, t_sort *info)
{
	info->index = 0;
	while (info->index < vec->len - 1)
	{
		if (info->index->cheapest == true)
			return (info->index);
		else
			info->index++;
	}
	return (0);
}

void	find_cheapest(t_vec *vec, t_sort *info)
{
	size_t	check;

	check = LONG_MAX;
	info->index = 0;
	while (info->index < vec->len - 1)
	{
		if (info->index->push_cost < check)
			check = info->index->push_cost;
		info->index++;
	}
	info->index = 0;
	while (info->index < vec->len - 1)
	{
		if (info->index->push_cost == check)
			info->index->cheapest = true;
		else
			info->index->cheapest = false;
		info->index++;
	}
}

void	calculate_cost(t_vec *a, t_vec *b size_t *index)
{
	if (info->index < (b->len - 1) / 2)
	{
		info->index->push_cost = info->index;
		info->index->above_median = true;
	}
	else
	{
		info->index->push_cost = (b->len - 1) - info->index;
		info->index->above_median = false;
	}
	if (info->index->target_index < (a->len - 1) / 2)
		info->index->target_index->above_median == true;
	else
		info->index->target_index->above_median == false;
}
