/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:31:00 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/17 17:30:35 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_smallest(t_vec *vec)
{
	size_t	i;
	int		nbr;

	i = 0;
	nbr = INT_MAX;
	while (i < vec->len - 1)
	{
		if (vec_int(vec, i) < nbr)
			nbr = vec_int(vec, i);
		i++;
	}
	i = 0;
	while (i < vec->len - 1)
	{
		if (nbr == vec_int(vec, i))
			return (i);
		else
			i++;
	}
	return (0);
}

void	find_target(t_vec *vec, int nbr, size_t *index)
{
	size_t	ind;
	int		check;
	int		max;
	int		min;

	max = vec_int(vec, find_biggest(vec));
	min = vec_int(vec, find_smallest(vec));
	check = INT_MIN;
	ind = 0;
	if (nbr < min)
		info->index->target_index = find_smallest(vec);
	else if (nbr > max)
		info->index->target_index = find_biggest(vec);
	else
	{
		while (ind++ < vec->len - 1)
		{
			if (vec_int(vec, ind) < nbr && vec_int(vec, ind) > check)
			{
				info->index->target_index = ind;
				check = vec_int(vec, ind);
			}
		}
	}
	calculate_cost(vec, info);
}

void	sort_many(t_vec *a, t_vec *b)
{
	t_sort	info;
	size_t	i;

	i = 0;
	pb(a, b);
	pb(a, b);
	if (vec_int(b, 0) < vec_int(b, 1))
		sb(b, false);
	while (a->len > 3)
	{
		i = 0;
		while (i++ < b->len - 1)
			find_target(b, vec_int(b, i), &info->index + i);
		find_cheapest(b, &info);
		move_to_b(a, b, &info);
	}
}
