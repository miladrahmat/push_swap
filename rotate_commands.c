/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:28:11 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/11 12:38:17 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_vec *a, bool check)
{
	int		ind0;
	void	*ind0ptr;

	if (a == NULL || a->memory == NULL)
		exit(EXIT_FAILURE);
	ind0 = *(int *)vec_get(a, 0);
	ind0ptr = &ind0;
	if (vec_remove(a, 0) < 0)
		exit(EXIT_FAILURE);
	if (vec_push(a, ind0ptr) < 0)
		exit(EXIT_FAILURE);
	if (check == false)
		ft_printf("ra\n");
}

void	rb(t_vec *b, bool check)
{
	int		ind0;
	void	*ind0ptr;

	if (b == NULL || b->memory == NULL)
		exit(EXIT_FAILURE);
	ind0 = *(int *)vec_get(b, 0);
	ind0ptr = &ind0;
	if (vec_remove(b, 0) < 0)
		exit(EXIT_FAILURE);
	if (vec_push(b, ind0ptr) < 0)
		exit(EXIT_FAILURE);
	if (check == false)
		ft_printf("rb\n");
}

void	rr(t_vec *a, t_vec *b)
{
	ra(a, true);
	rb(b, true);
	ft_printf("rr\n");
}
