/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:58:54 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/11 18:05:25 by mrahmat-         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_vec	a;
	t_vec	b;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			exit(EXIT_FAILURE);
	}
	check_args(argv, &a);
	if (argc == 2)
		split_free(argv);
	push_swap(&a, &b);
	return (0);
}
