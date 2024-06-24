/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:45:42 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/24 14:24:03 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "./libft/libft.h"
# include "./libft/vector.h"
# include "push_swap.h"

void	sa(t_vec *a, bool check);
void	sb(t_vec *b, bool check);
void	ss(t_vec *a, t_vec *b, bool check);
void	pa(t_vec *a, t_vec *b, bool check);
void	pb(t_vec *a, t_vec *b, bool check);
void	ra(t_vec *a, bool check);
void	rb(t_vec *b, bool check);
void	rr(t_vec *a, t_vec *b, bool check);
void	rra(t_vec *a, bool check);
void	rrb(t_vec *b, bool check);
void	rrr(t_vec *a, t_vec *b, bool check);
int		check_args(char **args, t_vec *a, size_t index);
int		check_dup(t_vec *a, long nbr);
void	rev_rotate(t_vec *a, t_vec *b, char *res);
void	push_cmd(t_vec *a, t_vec *b, char *res);
void	swap_cmd(t_vec *a, t_vec *b, char *res);
void	rotate_cmd(t_vec *a, t_vec *b, char *res);
int		check_errors(int argc, char **argv, t_vec *a);
void	split_free(char **arr);

#endif