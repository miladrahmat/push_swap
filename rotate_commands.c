/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:28:11 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/13 12:16:52 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_vec *a, bool check)
{
	int		ind0;
	void	*ind0ptr;

	if (a == NULL || a->memory == NULL)
		return ;
	ind0 = vec_int(a, 0);
	ind0ptr = &ind0;
	if (vec_remove(a, 0) < 0)
		return ;
	if (vec_push(a, ind0ptr) < 0)
		return ;
	if (check == false)
		ft_printf("ra\n");
}

void	rb(t_vec *b, bool check)
{
	int		ind0;
	void	*ind0ptr;

	if (b == NULL || b->memory == NULL)
		return ;
	ind0 = vec_int(b, 0);
	ind0ptr = &ind0;
	if (vec_remove(b, 0) < 0)
		return ;
	if (vec_push(b, ind0ptr) < 0)
		return ;
	if (check == false)
		ft_printf("rb\n");
}

void	rr(t_vec *a, t_vec *b)
{
	ra(a, true);
	rb(b, true);
	ft_printf("rr\n");
}
