/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:35:43 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/12 15:00:57 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	put_to_vector(char *str, t_vec *a)
{
	int		nbr;

	if (a == NULL)
		return (-1);
	else if (a->memory == NULL)
		if (vec_new(a, 1, sizeof(int)) < 0)
			return (-1);
	nbr = ft_atoi(str);
	if (check_dup(a, nbr) < 0)
		return (-1);
	if (vec_push(a, &nbr) < 0)
	{
		vec_free(a);
		return (-1);
	}
	return (1);
}

int	check_dup(t_vec *a, int nbr)
{
	size_t	i;

	i = 0;
	while (i < a->len)
	{
		if (nbr == vec_int(a, i) || nbr == 2147483647 || nbr == -2147483648)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		else
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
			if (args[index][w_i] < '0' || args[index][w_i] > '9')
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			else
				w_i++;
		}
		if (put_to_vector(args[index], a) < 0)
			return (-1);
		index++;
	}
	return (1);
}
