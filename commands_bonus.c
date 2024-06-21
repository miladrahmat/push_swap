/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- < mrahmat-@student.hive.fi >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:00:53 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/21 18:11:30 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.c"

void	rotate_cmd(t_vec *a, t_vec *b, char *res)
{
	size_t	w_i;

	w_i = 1;	
	if (res[w_i] == 'a')
		ra(a, true);
	else if (res[w_i] == 'b')
		rb(b, true);
	else if (res[w_i] == 'r')
		rr(a, b, true);
}

void	swap_cmd(t_vec *a, t_vec *b, char *res)
{
	size_t	w_i;

	w_i = 1;
	if (res[w_i] == 'a')
		sa(a, true);
	else if (res[w_i] == 'b')
		sb(b, true);
	else if(res[w_i] == 's')
		ss(a, b, true);
}

void	push_cmd(t_vec *a, t_vec *b, char *res)
{
	size_t	w_i;

	w_i = 1;
	if (res[w_i] == 'a')
		pa(a, b, true);
	else if (res[w_i] == 'b')
		pb(a, b, true);
}

void	rev_rotate(t_vec *a, t_vec *b, char *res)
{
	size_t	w_i;

	w_i = 2;
	if (res[w_i] == 'a')
		rra(a, true);
	else if (res[w_i] == 'b')
		rrb(b, true);
	else if (res[w_i] == 'r')
		rrr(a, b, true);
}
