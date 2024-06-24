/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:18:18 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/24 11:54:46 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include "./libft/vector.h"

typedef struct s_sort
{
	size_t	temp_ind_a;
	size_t	temp_ind_b;
	size_t	index_a;
	size_t	index_b;
	size_t	temp_cost_a;
	size_t	temp_cost_b;
	size_t	temp_total;
	size_t	push_cost_a;
	size_t	push_cost_b;
	size_t	total_cost;
	bool	above_median_a;
	bool	above_median_b;
}	t_sort;

//commands
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

//error check
int		check_args(char **args, t_vec *a, size_t index);
int		check_dup(t_vec *a, long nbr);

//sorting
int		is_sorted(t_vec *a);
void	sort_three(t_vec *a);
void	sort_many(t_vec *a, t_vec *b);
int		push_swap(t_vec *a, t_vec *b);
void	move_to_b(t_vec *a, t_vec *b, t_sort *info);
void	move_to_a(t_vec *a, t_vec *b, t_sort *info);
void	sort_rest(t_vec *a);

//helper funcs
size_t	find_biggest_ind(t_vec *vec);
size_t	find_smallest_ind(t_vec *vec);
int		find_smallest_nbr(t_vec *vec);
int		find_biggest_nbr(t_vec *vec);
void	get_info_b(t_vec *a, t_vec *b, t_sort *info);
void	get_info_a(t_vec *a, t_vec *b, t_sort *info);
void	reset_info(t_sort *info);
int		check_errors(int argc, char **argv, t_vec *a);
void	split_free(char **arr);

#endif