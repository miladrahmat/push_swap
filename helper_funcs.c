/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:15:53 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/08/20 15:32:49 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_smallest_ind(t_vec *vec)
{
	size_t	i;
	int		nbr;

	i = 0;
	nbr = INT_MAX;
	while (i < vec->len)
	{
		if (vec_int(vec, i) < nbr)
			nbr = vec_int(vec, i);
		i++;
	}
	i = 0;
	while (i < vec->len)
	{
		if (nbr == vec_int(vec, i))
			return (i);
		else
			i++;
	}
	return (0);
}

size_t	find_biggest_ind(t_vec *vec)
{
	size_t	i;
	int		nbr;

	i = 0;
	nbr = INT_MIN;
	while (i < vec->len)
	{
		if (vec_int(vec, i) > nbr)
			nbr = vec_int(vec, i);
		i++;
	}
	i = 0;
	while (i < vec->len)
	{
		if (vec_int(vec, i) == nbr)
			return (i);
		else
			i++;
	}
	return (0);
}

int	find_smallest_nbr(t_vec *vec)
{
	int	nbr;

	nbr = vec_int(vec, find_smallest_ind(vec));
	return (nbr);
}

int	find_biggest_nbr(t_vec *vec)
{
	int	nbr;

	nbr = vec_int(vec, find_biggest_ind(vec));
	return (nbr);
}

void	reset_info(t_sort *info)
{
	info->temp_ind_a = 0;
	info->temp_ind_b = 0;
	info->index_a = 0;
	info->index_b = 0;
	info->temp_cost_a = 0;
	info->temp_cost_b = 0;
	info->temp_total = SIZE_MAX;
	info->push_cost_a = 0;
	info->push_cost_b = 0;
	info->total_cost = SIZE_MAX;
	info->above_median_a = false;
	info->above_median_b = false;
}
