/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:26:18 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/13 12:16:48 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_vec *a, t_vec *b)
{
	int		ind0;
	void	*ind0ptr;

	if (a == NULL || b == NULL)
		return ;
	else if (a->memory == NULL || b->memory == NULL)
		return ;
	ind0 = vec_int(a, 0);
	ind0ptr = &ind0;
	if (vec_remove(a, 0) < 0)
		return ;
	if (vec_insert(b, ind0ptr, 0) < 0)
		return ;
	ft_printf("pa\n");
}

void	pa(t_vec *a, t_vec *b)
{
	int		ind0;
	void	*ind0ptr;

	if (a == NULL || b == NULL)
		return ;
	else if (a->memory == NULL || b->memory == NULL)
		return ;
	ind0 = vec_int(b, 0);
	ind0ptr = &ind0;
	if (vec_remove(b, 0) < 0)
		return ;
	if (vec_insert(a, ind0ptr, 0) < 0)
		return ;
	ft_printf("pa\n");
}
