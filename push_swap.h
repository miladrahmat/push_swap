/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:18:18 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/17 17:39:42 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include "./libft/vector.h"

typedef struct s_sort
{
	int		nbr;
	size_t	index;
	size_t	target_index;
	size_t	push_cost;
	bool	cheapest;
	bool	above_median;
}	t_sort;

void	sa(t_vec *a, bool check);
void	sb(t_vec *b, bool check);
void	ss(t_vec *a, t_vec *b);
void	pa(t_vec *a, t_vec *b);
void	pb(t_vec *a, t_vec *b);
void	ra(t_vec *a, bool check);
void	rb(t_vec *b, bool check);
void	rr(t_vec *a, t_vec *b);
void	rra(t_vec *a, bool check);
void	rrb(t_vec *b, bool check);
void	rrr(t_vec *a, t_vec *b);
int		is_sorted(t_vec *a);
void	sort_three(t_vec *a);
int		push_swap(t_vec *a, t_vec *b);
int		check_args(char **args, t_vec *a, size_t index);
int		check_dup(t_vec *a, int nbr);
size_t	find_biggest(t_vec *vec);
size_t	find_smallest(t_vec *vec);
void	find_target(t_vec *a, int nbr, size_t index);
void	calculate_cost(t_vec *vec, t_sort *info);
void	find_cheapest(t_vec *vec, t_sort *info);
void	sort_many(t_vec *a, t_vec *b);

#endif