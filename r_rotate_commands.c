/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:41:41 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/11 12:49:40 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_vec *a, bool check)
{
	int		ind_last;
	void	*ind_lastptr;

	if (a == NULL || a->memory == NULL)
		exit(EXIT_FAILURE);
	ind_last = *(int *)vec_get(a, a->len - 1);
	ind_lastptr = &ind_last;
	if (vec_remove(a, a->len - 1) < 0)
		exit(EXIT_FAILURE);
	if (vec_insert(a, ind_lastptr, 0) < 0)
		exit(EXIT_FAILURE);
	if (check == false)
		ft_printf("rra\n");
}

void	rrb(t_vec *b, bool check)
{
	int		ind_last;
	void	*ind_lastptr;

	if (b == NULL || b->memory == NULL)
		exit(EXIT_FAILURE);
	ind_last = *(int *)vec_get(b, b->len - 1);
	ind_lastptr = &ind_last;
	if (vec_remove(b, b->len - 1) < 0)
		exit(EXIT_FAILURE);
	if (vec_insert(b, ind_lastptr, 0) < 0)
		exit(EXIT_FAILURE);
	if (check == false)
		ft_printf("rrb\n");
}

void	rrr(t_vec *a, t_vec *b)
{
	rra(a, true);
	rrb(b, true);
	ft_printf("rrr\n");
}
