/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_repertoir5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:55:49 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/17 17:02:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	matrix_put_element(t_mat *dst, int i, int j, double d)
{
	matrix_goto_element(dst, i, j)->d = d;
	return ;
}

void	matrix_put_matrix(t_mat *dest, t_mat *ref, int i, int j)
{
	t_mat	*scrn;
	int		x;
	int		y;

	scrn = matrix_empty(dest->m, dest->n);
	x = 1;
	while (x <= 1)
	{
		y = 1;
		while (y <= j)
		{
			matrix_put_element(scrn, i + x - 1, j + y - 1,
				matrix_get_element(ref, x, y));
			y++;
		}
		x++;
	}
	matrix_screen(dest, scrn);
	matrix_destroy(scrn);
	return ;
}

t_mat	*matrix_get_submatrix(t_mat *m, t_vec *range)
{
	t_mat	*subm;
	int		i[2];
	int		j[2];
	int		i0fixed;

	vector_range_fix(range);
	if (!vector_range_check_boundaries(range, m))
		ft_die(MATRIXSUBMATRIXERR, ERRMATRIXSUBMATRIX);
	j[0] = vector_get_element(range, 2);
	j[1] = vector_get_element(range, 4);
	i0fixed = vector_get_element(range, 1);
	i[1] = vector_get_element(range, 3);
	subm = matrix_new();
	subm->m = i[1] - i0fixed + 1;
	subm->n = j[1] - j[0] + 1;
	while (j[0] <= j[1])
	{
		i[0] = i0fixed;
		while (i[0] <= i[1])
			subm->i = \
				lstdbl_addlast(subm->i, matrix_get_element(m, i[0]++, j[0]));
		j[0]++;
	}
	return (subm);
}

t_vec	*matrix_get_vector(t_mat *m, int j)
{
	t_vec	*temp;
	t_vec	*extracted;

	temp = vector_build(1, j, m->m, j);
	extracted = (t_vec *)matrix_get_submatrix(m, temp);
	vector_destroy(temp);
	return (extracted);
}

t_mat	*matrix_copy(t_mat *a)
{
	t_mat	*mcp;

	mcp = malloc(sizeof(t_mat));
	return ((t_mat *)ft_memcpy(mcp, a, sizeof(t_mat)));
}
