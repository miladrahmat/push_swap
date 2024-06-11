/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:16:10 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/11 17:16:59 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_vec *a)
{
	size_t	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (*(int *)vec_get(a, i) > *(int *)vec_get(a, i + 1))
			return (-1);
		else
			i++;
	}
	return (1);
}

void	sort_three(t_vec *a)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (*(int *)vec_get(a, 0) > *(int *)vec_get(a, 1))
		{
			if (*(int *)vec_get(a, 0) > *(int *)vec_get(a, 2))
				ra(a, false);
			else
				sa(a, true);
		}
	}
	if (is_sorted(a) > 0)
		return ;
	else
		sort_three(a);
}

int	push_swap(t_vec *a, t_vec *b)
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
