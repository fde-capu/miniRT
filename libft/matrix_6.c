/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:00:20 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 15:27:07 by fde-capu         ###   ########.fr       */
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
	t_mat	*minor;
	int		i;
	int		j;

	mom = matrix_new();
	i = 1;
	while (i <= a->m)
	{
		j = 1;
		while (j <= a->n)
		{
			minor = matrix_minor(a, i, j);
			mom->i = lstdbl_addlast(mom->i, matrix_determinant(minor));
			matrix_destroy(minor);
			j++;
		}
		i++;
	}
	mom->m = a->m;
	mom->n = a->n;
	return (mom);
}

t_mat	*matrix_subtract(t_mat *a, t_mat *b)
{
	t_mat	*subtracted;
	t_mat	*temp;

	temp = matrix_scalar_multiply(b, -1.0);
	subtracted = matrix_sum(a, temp);
	matrix_destroy(temp);
	return (subtracted);
}

t_mat	*matrixx(t_mat *old, t_mat *new)
{
	matrix_destroy(old);
	return (new);
}

t_vec	*matrix_get_line_transposed(t_mat *m, int i)
{
	t_mat	*linet;

	linet = matrix_get_line(m, i);
	linet = matrixx(linet, matrix_transpose(linet));
	return ((t_vec *)linet);
}
