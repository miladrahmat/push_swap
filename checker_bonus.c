/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- < mrahmat-@student.hive.fi >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:45:06 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/21 18:18:02 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	exec_commands(t_vec *a, t_vec *b, char **res)
{
	size_t	arr_i;
	size_t	w_i;
	size_t	len;

	arr_i = 0;
	w_i = 0;
	while (res[arr_i] != NULL)
	{
		len = ft_strlen(res[arr_i]);
		if (len == 2)
		{
			if (res[arr_i][w_i] == 'r')
				rotate_cmd(a, b, &res[arr_i]);
			else if (res[arr_i][w_i] == 's');
				swap_cmd(a, b, &res[arr_i]);
			else if (res[arr_i][w_i] == 'p')
				push_cmd(a, b, &res[arr_i]);
		}
		else if (len == 3)
			rev_rotate(a, b, &res[arr_i]);
		arr_i++;
	}
}

void	get_result(char ***res)
{
	size_t	i;

	i = 0;
	while (*res[i] != NULL)
	{
		*res[i] = get_next_line(0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_vec	a;
	t_vec	b;
	int		check;
	char	**res;

	vec_new(&a, 1, sizeof(int));
	vec_new(&b, 1, sizeof(int));
	check = check_errors(argc, argv, &a);
	if (check < 0)
	{
		vec_free(&a);
		vec_free(&b);
		exit(EXIT_FAILURE);
	}
	get_result(&res);
	exec_commands(&a, &b, res);
}
