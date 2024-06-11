/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:35:43 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/11 18:19:47 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	put_to_vector(char *str, t_vec *a)
{
	int		nbr;
	void	*nbrptr;

	if (a == NULL)
		return (-1);
	else if (a->memory == NULL)
		if (vec_new(a, 1, sizeof(int)) < 0)
			return (-1);
	nbr = ft_atoi(str);
	nbrptr = &nbr;
	if (vec_push(a, nbrptr) < 0)
	{
		vec_free(a);
		return (-1);
	}
	return (1);
}

static int	check_dup(char **str)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(str);
	if (len == 1)
		return (1);
	j = 1;
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (str[i] == str[j])
				return (-1);
			else
				i++;
		}
		j++;
	}
	return (1);
}

void	check_args(char **args, t_vec *a)
{
	size_t	len;
	size_t	arr_i;
	size_t	w_i;

	if (check_dup(args) < 0)
		exit(EXIT_FAILURE);
	arr_i = 1;
	while (args[arr_i] != NULL)
	{
		w_i = 0;
		len = ft_strlen(args[arr_i]);
		while (w_i < len)
		{
			if (args[arr_i][w_i] < '0' || args[arr_i][w_i] > '9')
			{
				ft_putstr_fd("Error", 2);
				exit(EXIT_FAILURE);
			}
			else
				w_i++;
		}
		if (put_to_vector(args[arr_i], a) < 0)
			exit(EXIT_FAILURE);
		arr_i++;
	}
}
