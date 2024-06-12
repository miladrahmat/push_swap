/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:16:10 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/12 15:04:26 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_vec *a)
{
	size_t	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (vec_int(a, i) > vec_int(a, i + 1))
			return (-1);
		else
			i++;
	}
	return (1);
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
		printf("\n");
		if (vec_int(a, 2) < vec_int(a, 0) && vec_int(a, 2) < vec_int(a, 1))
			rra(a, false);
		else if (vec_int(a, 0) > vec_int(a, 1))
		{
			if (vec_int(a, 0) > vec_int(a, 2))
				ra(a, false);
			else
				sa(a, false);
		}
	}
}

int	push_swap(t_vec *a)
{
	if (a == NULL || a->memory == NULL)
		exit(EXIT_FAILURE);
	if (a->len == 1 || is_sorted(a) > 0)
		return (1);
	if (a->len <= 3)
		sort_three(a);
	/* else if (a->len <= 5)
		sort_five(a, b); */
	return (0);
}
