/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:31:00 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/14 15:27:59 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	find_smallest(t_vec *vec)
{
	size_t	i;
	int		nbr;

	i = 0;
	nbr = 2147483647;
	while (i < vec->len - 1)
	{
		if (vec_int(vec, i) < nbr)
			nbr = vec_int(vec, i);
		i++;
	}
	i = 0;
	while (i < vec->len - 1)
	{
		if (nbr == vec_int(vec, i))
			return (i);
		else
			i++;
	}
	return (0);
}

void	find_target(t_vec *a, t_vec *b, t_sort *check_b)
{
	size_t	a_i;
	size_t	b_i;

	a_i = 0;
	check_b->nbr = 2147483647;
	
}

void	sort_many(t_vec *a, t_vec *b)
{
	t_sort	check_a;
	t_sort	check_b;

	while (a->len > 3)
		pb(a, b);
	sort_three(a);
	find_target(a, b, &check_b);
}
