/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:45:06 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/24 19:06:02 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_sorted_checker(t_vec *a, t_vec *b)
{
	size_t	i;

	i = 0;
	if (b->len != 0)
		return (-1);
	while (i < a->len - 1)
	{
		if (vec_int(a, i) > vec_int(a, i + 1))
			return (-1);
		i++;
	}
	return (1);
}

static int	exec_command(t_vec *a, t_vec *b, char *res)
{
	if (ft_strncmp(res, "ra\n", 3) == 0 && a->len > 0)
		ra(a, true);
	else if (ft_strncmp(res, "rb\n", 3) == 0 && b->len > 0)
		rb(b, true);
	else if (ft_strncmp(res, "rra\n", 4) == 0 && a->len > 0)
		rra(a, true);
	else if (ft_strncmp(res, "rrb\n", 4) == 0 && b->len > 0)
		rrb(b, true);
	else if (ft_strncmp(res, "rr\n", 3) == 0 && a->len > 0 && b->len > 0)
		rr(a, b, true);
	else if (ft_strncmp(res, "rrr\n", 4) == 0 && a->len > 0 && b->len > 0)
		rrr(a, b, true);
	else if (ft_strncmp(res, "pa\n", 3) == 0 && b->len > 0)
		pa(a, b, true);
	else if (ft_strncmp(res, "pb\n", 3) == 0 && a->len > 0)
		pb(a, b, true);
	else if (ft_strncmp(res, "sa\n", 3) == 0 && a->len > 0)
		sa(a, true);
	else if (ft_strncmp(res, "sb\n", 3) == 0 && b->len > 0)
		sb(b, true);
	else if (ft_strncmp(res, "ss\n", 3) == 0 && a->len > 0 && b->len > 0)
		ss(a, b, true);
	else
		return (-1);
	return (1);
}

static void	get_result(t_vec *a, t_vec *b)
{
	char	*res;

	res = get_next_line(0);
	while (res != NULL)
	{
		if (exec_command(a, b, res) < 0)
		{
			free(res);
			vec_free(a);
			vec_free(b);
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
		free(res);
		res = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_vec	a;
	t_vec	b;
	int		check;

	vec_new(&a, 1, sizeof(int));
	vec_new(&b, 1, sizeof(int));
	check = check_errors(argc, argv, &a);
	if (check < 0)
	{
		vec_free(&a);
		vec_free(&b);
		exit(EXIT_FAILURE);
	}
	get_result(&a, &b);
	if (is_sorted_checker(&a, &b) < 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	vec_free(&a);
	vec_free(&b);
	exit(EXIT_SUCCESS);
}
