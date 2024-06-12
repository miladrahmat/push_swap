/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:26:18 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/12 10:33:40 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_vec *a, t_vec *b)
{
	int		ind0;
	void	*ind0ptr;

	if (a == NULL || b == NULL)
		exit(EXIT_FAILURE);
	else if (a->memory == NULL || b->memory == NULL)
		exit(EXIT_FAILURE);
	ind0 = *(int *)vec_get(a, 0);
	ind0ptr = &ind0;
	if (vec_remove(a, 0) < 0)
		exit(EXIT_FAILURE);
	if (vec_insert(b, ind0ptr, 0) < 0)
		exit(EXIT_FAILURE);
	ft_printf("pa\n");
}

void	pa(t_vec *a, t_vec *b)
{
	int		ind0;
	void	*ind0ptr;

	if (a == NULL || b == NULL)
		exit(EXIT_FAILURE);
	else if (a->memory == NULL || b->memory == NULL)
		exit(EXIT_FAILURE);
	ind0 = *(int *)vec_get(b, 0);
	ind0ptr = &ind0;
	if (vec_remove(b, 0) < 0)
		exit(EXIT_FAILURE);
	if (vec_insert(a, ind0ptr, 0) < 0)
		exit(EXIT_FAILURE);
	ft_printf("pa\n");
}
