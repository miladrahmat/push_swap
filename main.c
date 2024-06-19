/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:58:54 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/19 13:33:03 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr[i]);
	arr[i] = NULL;
	free(arr);
	arr = NULL;
}

static int	check_errors(int argc, char **argv, t_vec *a)
{
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (-1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (-1);
		if (check_args(argv, a, 0) < 0)
			return (-3);
	}
	else if (check_args(argv, a, 1) < 0)
		return (-2);
	return (1);
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
		if (check == -3)
			split_free(argv);
		vec_free(&a);
		vec_free(&b);
		exit(EXIT_FAILURE);
	}
	push_swap(&a, &b);
	vec_free(&a);
	vec_free(&b);
	exit(EXIT_SUCCESS);
}
