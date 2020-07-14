/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ops3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:55:58 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 12:13:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat	*matrix_copy(t_mat *a)
{
	t_mat	*mcp;

	mcp = malloc(sizeof(t_mat));
	return ((t_mat *)ft_memcpy(mcp, a, sizeof(t_mat)));
}

t_mat	*matrix_of_minors(t_mat *a)
{
	t_mat	*mom;
	int		i;
	int		j;

	mom = ft_calloc(sizeof(t_mat), 1);
	i = 1;
	while (i <= a->m)
	{
		j = 1;
		while (j <= a->n)
		{
			mom->i = !mom->i ? \
				lstdbl_new(matrix_determinant(matrix_minor(a, i, j))) : \
				lstdbl_addlast(mom->i,
					matrix_determinant(matrix_minor(a, i, j)));
			j++;
		}
		i++;
	}
	mom->m = a->m;
	mom->n = a->n;
	return (mom);
}
