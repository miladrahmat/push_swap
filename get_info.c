/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- < mrahmat-@student.hive.fi >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:41:44 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/21 15:31:19 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_cost(t_vec *a, t_vec *b, t_sort *info)
{
	size_t	median_a;
	size_t	median_b;

	median_a = (a->len - 1) / 2;
	median_b = (b->len - 1) / 2;
	if (info->temp_ind_a <= median_a)
		info->temp_cost_a = info->temp_ind_a;
	else if (info->temp_ind_a > median_a)
		info->temp_cost_a = a->len - info->temp_ind_a;
	if (info->temp_ind_b <= median_b)
		info->temp_cost_b = info->temp_ind_b;
	else if (info->temp_ind_b > median_b)
		info->temp_cost_b = b->len - info->temp_ind_b;
	if (info->temp_cost_a == info->temp_cost_b)
		info->temp_total = info->temp_cost_a;
	else if ((info->temp_ind_a <= median_a && info->temp_ind_b <= median_b) \
		|| (info->temp_ind_a > median_a && info->temp_ind_b > median_b))
	{
		if (info->temp_cost_a > info->temp_cost_b)
			info->temp_total = info->temp_cost_a;
		else
			info->temp_total = info->temp_cost_b;
	}
	else
		info->temp_total = info->temp_cost_a + info->temp_cost_b;
}

static void	find_target_b(t_vec *b, int nbr, t_sort *info)
{
	size_t	ind;
	int		check;

	check = INT_MIN;
	ind = 0;
	if (nbr < find_smallest_nbr(b))
		info->temp_ind_b = find_biggest_ind(b);
	else
	{
		while (ind < b->len)
		{
			if (vec_int(b, ind) < nbr && vec_int(b, ind) > check)
				check = vec_int(b, ind);
			ind++;
		}
		ind = 0;
		while (ind < b->len)
		{
			if (vec_int(b, ind) == check)
				info->temp_ind_b = ind;
			ind++;
		}
	}
}

static void	find_target_a(t_vec *a, int nbr, t_sort *info)
{
	size_t	ind;
	int		check;

	check = INT_MAX;
	ind = 0;
	if (nbr > find_biggest_nbr(a))
		info->temp_ind_a = find_smallest_ind(a);
	else
	{
		while (ind < a->len)
		{
			if (vec_int(a, ind) > nbr && vec_int(a, ind) < check)
				check = vec_int(a, ind);
			ind++;
		}
		ind = 0;
		while (ind < a->len)
		{
			if (vec_int(a, ind) == check)
				info->temp_ind_a = ind;
			ind++;
		}
	}
}

void	get_info_b(t_vec *a, t_vec *b, t_sort *info)
{
	info->temp_ind_a = 0;
	while (info->temp_ind_a < a->len)
	{
		find_target_b(b, vec_int(a, info->temp_ind_a), info);
		calculate_cost(a, b, info);
		if (info->temp_total < info->total_cost)
		{
			info->index_a = info->temp_ind_a;
			info->index_b = info->temp_ind_b;
			info->push_cost_a = info->temp_cost_a;
			info->push_cost_b = info->temp_cost_b;
			info->total_cost = info->temp_total;
			if (info->index_a <= (a->len - 1) / 2)
				info->above_median_a = true;
			else
				info->above_median_a = false;
			if (info->index_b <= (b->len - 1) / 2)
				info->above_median_b = true;
			else
				info->above_median_b = false;
		}
		info->temp_ind_a++;
	}
}

void	get_info_a(t_vec *a, t_vec *b, t_sort *info)
{
	info->temp_ind_b = 0;
	while (info->temp_ind_b < b->len)
	{
		find_target_a(a, vec_int(b, info->temp_ind_b), info);
		calculate_cost(a, b, info);
		if (info->temp_total < info->total_cost)
		{
			info->index_a = info->temp_ind_a;
			info->index_b = info->temp_ind_b;
			info->push_cost_a = info->temp_cost_a;
			info->push_cost_b = info->temp_cost_b;
			info->total_cost = info->temp_total;
			if (info->index_a <= (a->len - 1) / 2)
				info->above_median_a = true;
			else
				info->above_median_a = false;
			if (info->index_b <= (b->len - 1) / 2)
				info->above_median_b = true;
			else
				info->above_median_b = false;
		}
		info->temp_ind_b++;
	}
}
