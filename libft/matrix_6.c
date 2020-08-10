/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:00:20 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/10 14:18:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	matrix_destroy(t_mat *mat)
{
	if (!mat)
		return ;
	lstdbl_destroy(mat->i);
	free(mat);
	return ;
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
