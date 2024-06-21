/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- < mrahmat-@student.hive.fi >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:41:41 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/21 17:34:36 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_vec *a, bool check)
{
	int		ind_last;
	void	*ind_lastptr;

	if (a == NULL || a->memory == NULL)
		return ;
	ind_last = vec_int(a, a->len - 1);
	ind_lastptr = &ind_last;
	if (vec_remove(a, a->len - 1) < 0)
		return ;
	if (vec_insert(a, ind_lastptr, 0) < 0)
		return ;
	if (check == false)
		ft_printf("rra\n");
}

void	rrb(t_vec *b, bool check)
{
	int		ind_last;
	void	*ind_lastptr;

	if (b == NULL || b->memory == NULL)
		return ;
	ind_last = vec_int(b, b->len - 1);
	ind_lastptr = &ind_last;
	if (vec_remove(b, b->len - 1) < 0)
		return ;
	if (vec_insert(b, ind_lastptr, 0) < 0)
		return ;
	if (check == false)
		ft_printf("rrb\n");
}

void	rrr(t_vec *a, t_vec *b, bool check)
{
	rra(a, true);
	rrb(b, true);
	if (check == false)
		ft_printf("rrr\n");
}
