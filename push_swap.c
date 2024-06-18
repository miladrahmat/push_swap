/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:16:10 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/17 17:29:29 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_vec *a)
{
	size_t	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (vec_int(a, i) > vec_int(a, i + 1))
			return (-1);
		i++;
	}
	return (1);
}

size_t	find_biggest(t_vec *vec)
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

void	sort_five(t_vec *a, t_vec *b)
{
	t_sort	check;

	pb(a, b);
	pb(a, b);
	sort_three(a);
	while (b->len > 0)
	{
		check.index = find_biggest(a);
		check.nbr = vec_int(a, check.index);
		if (vec_int(b, 0) > check.nbr && check.index == a->len - 1)
		{
			pa(a, b);
			ra(a, false);
		}
		else if (vec_int(b, 0) < vec_int(a, 0))
			pa(a, b);
		else
			ra(a, false);
	}
	while (is_sorted(a) < 0)
	{
		if (find_biggest(a) < (a->len -1) / 2)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_three(t_vec *a)
{
	if (a->len == 2)
	{
		if (vec_int(a, 0) > vec_int(a, 1))
			sa(a, false);
		return ;
	}
	while (is_sorted(a) < 0)
	{
		if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 0) < vec_int(a, 2))
			sa(a, false);
		else if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 1) < vec_int(a, 2))
			ra(a, false);
		else if (vec_int(a, 0) > vec_int(a, 2) && vec_int(a, 0) < vec_int(a, 1))
			rra(a, false);
		else if (vec_int(a, 0) < vec_int(a, 1) && vec_int(a, 1) > vec_int(a, 2))
		{
			sa(a, false);
			ra(a, false);
		}
		else if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 1) > vec_int(a, 2))
		{
			sa(a, false);
			rra(a, false);
		}
	}
}

int	push_swap(t_vec *a, t_vec *b)
{
	if (a == NULL || a->memory == NULL)
		exit(EXIT_FAILURE);
	if (vec_new(b, 1, sizeof(int)) < 0)
	{
		vec_free(a);
		exit(EXIT_FAILURE);
	}
	if (a->len == 1 || is_sorted(a) > 0)
		return (0);
	if (a->len <= 3)
		sort_three(a);
	else if (a->len <= 5)
		sort_five(a, b);
	else
		sort_many(a, b);
	return (0);
}
