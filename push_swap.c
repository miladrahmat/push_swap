/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:16:10 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/19 13:35:50 by mrahmat-         ###   ########.fr       */
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

void	sort_many(t_vec *a, t_vec *b)
{
	t_sort	info_b;
	t_sort	info_a;

	pb(a, b);
	pb(a, b);
	if (vec_int(b, 0) < vec_int(b, 1))
		sb(b, false);
	while (a->len > 3)
	{
		reset_info(&info_b);
		get_info_b(a, b, &info_b);
		move_to_b(a, b, &info_b);
	}
	sort_three(a);
	while (b->len > 0)
	{
		reset_info(&info_a);
		get_info_a(a, b, &info_a);
		move_to_a(a, b, &info_a);
	}
	sort_rest(a);
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
	if (a->len == 1 || is_sorted(a) > 0)
		return (0);
	if (a->len <= 3)
		sort_three(a);
	else
		sort_many(a, b);
	return (0);
}
