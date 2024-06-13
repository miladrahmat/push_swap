/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:58:54 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/13 15:18:53 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int	main(int argc, char **argv)
{
	t_vec	a;
	t_vec	b;
	size_t	i;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			exit(EXIT_FAILURE);
		if (check_args(argv, &a, 0) < 0)
		{
			split_free(argv);
			exit(EXIT_FAILURE);
		}
	}
	else if (check_args(argv, &a, 1) < 0)
	{
		if (a.memory != NULL)
			vec_free(&a);
		exit(EXIT_FAILURE);
	}
	push_swap(&a, &b);
	i = 0;
	while (i < a.len)
	{
		printf("%d ", vec_int(&a, i));
		i++;
	}
	printf("\n");
	vec_free(&a);
	vec_free(&b);
	exit(EXIT_SUCCESS);
}
