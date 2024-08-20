/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:26:18 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/08/20 15:33:03 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_vec *a, t_vec *b, bool check)
{
	int		ind0;
	void	*ind0ptr;

	if (a == NULL || b == NULL)
		return ;
	else if (a->memory == NULL || b->memory == NULL)
		return ;
	else if (b->len * b->elem_size >= b->alloc_size)
		if (vec_resize(b, b->len * 2) < 0)
			return ;
	ind0 = vec_int(a, 0);
	ind0ptr = &ind0;
	if (vec_remove(a, 0) < 0)
		return ;
	if (vec_insert(b, ind0ptr, 0) < 0)
		return ;
	if (check == false)
		ft_printf("pb\n");
}

void	pa(t_vec *a, t_vec *b, bool check)
{
	int		ind0;
	void	*ind0ptr;

	if (a == NULL || b == NULL)
		return ;
	else if (a->memory == NULL || b->memory == NULL)
		return ;
	else if (a->len * a->elem_size >= a->alloc_size)
		if (vec_resize(b, a->len * 2) < 0)
			return ;
	ind0 = vec_int(b, 0);
	ind0ptr = &ind0;
	if (vec_remove(b, 0) < 0)
		return ;
	if (vec_insert(a, ind0ptr, 0) < 0)
		return ;
	if (check == false)
		ft_printf("pa\n");
}
