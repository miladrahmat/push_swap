/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:35:43 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/24 19:03:10 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	put_to_vector(char *str, t_vec *a)
{
	long	nbr;
	int		res;

	if (a == NULL)
		return (-1);
	nbr = ft_atol(str);
	if (check_dup(a, nbr) < 0)
		return (-1);
	res = (int)nbr;
	if ((long)res != nbr)
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	if (vec_push(a, &res) < 0)
		return (-1);
	return (1);
}

int	check_dup(t_vec *a, long nbr)
{
	size_t	i;

	i = 0;
	if (a->len == 0)
		return (1);
	while (i < a->len)
	{
		if (nbr == (long)vec_int(a, i) || nbr > INT_MAX || nbr < INT_MIN)
		{
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	check_args(char **args, t_vec *a, size_t index)
{
	size_t	len;
	size_t	w_i;

	while (args[index] != NULL)
	{
		w_i = 0;
		len = ft_strlen(args[index]);
		while (w_i < len)
		{
			if (((args[index][0] < '0' || args[index][0] > '9') \
				&& (args[index][0] != '+' && args[index][0] != '-')) \
					|| ((args[index][0] == '+' || args[index][0] == '-') \
						&& len == 1) || ((args[index][w_i] < '0' || \
							args[index][w_i] > '9') && w_i != 0))
			{
				ft_putendl_fd("Error", 2);
				return (-1);
			}
			w_i++;
		}
		if (put_to_vector(args[index], a) < 0)
			return (-1);
		index++;
	}
	return (1);
}

void	split_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	check_errors(int argc, char **argv, t_vec *a)
{
	char	**arr;

	if (argc < 2)
		return (-1);
	if (argv[1][0] == '\0')
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	else if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (arr == NULL)
			return (-1);
		else if (check_args(arr, a, 0) < 0)
		{
			split_free(arr);
			return (-1);
		}
		split_free(arr);
	}
	else if (check_args(argv, a, 1) < 0)
		return (-1);
	return (1);
}
