/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- < mrahmat-@student.hive.fi >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:43:32 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/21 17:37:27 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_vec *a, bool check)
{
	int		ind0;
	void	*ind0ptr;

	if (a == NULL || a->memory == NULL)
		return ;
	ind0 = vec_int(a, 0);
	ind0ptr = &ind0;
	if (vec_remove(a, 0) < 0)
		return ;
	if (vec_insert(a, ind0ptr, 1) < 0)
		return ;
	if (check == false)
		ft_printf("sa\n");
}

void	sb(t_vec *b, bool check)
{
	int		ind0;
	void	*ind0ptr;

	if (b == NULL || b->memory == NULL)
		return ;
	ind0 = vec_int(b, 0);
	ind0ptr = &ind0;
	if (vec_remove(b, 0) < 0)
		return ;
	if (vec_insert(b, ind0ptr, 1) < 0)
		return ;
	if (check == false)
		ft_printf("sb\n");
}

void	ss(t_vec *a, t_vec *b, bool check)
{
	sa(a, true);
	sb(b, true);
	if (check == false)
		ft_printf("ss\n");
}
