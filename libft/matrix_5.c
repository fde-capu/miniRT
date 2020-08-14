/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:00:14 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/14 11:44:29 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	matrix_put_element(t_mat *dst, int i, int j, double d)
{
	t_dbl	*h;

	h = matrix_goto_element(dst, i, j);
	h->d = d;
	return ;
}

void	matrix_put_matrix(t_mat *dest, t_mat *ref, int i, int j)
{
	t_dbl	*h;
	int		vector_num;
	t_vec	*vec;
	t_dbl	*vh;
	int		v_count;

	h = matrix_goto_element(dest, i, j);
	vector_num = 1;
	vec = vector_new();
	while (vector_num <= ref->n)
	{
		vec = vectorx(vec, matrix_get_vector(ref, vector_num));
		vh = vec->i;
		v_count = 0;
		while (vh)
		{
			matrix_put_element(dest, i + v_count, j + vector_num - 1, vh->d);
			v_count++;
			vh = vh->nx;
		}
		vector_num++;
	}
	vector_destroy(vec);
	return ;
}

t_mat	*matrix_get_submatrix(t_mat *m, t_vec *range)
{
	t_mat	*subm;
	int		i[2];
	int		j[2];
	int		i0fixed;

	vector_range_fix(range);
	if (!vector_range_check_boundaries(m, range))
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

	temp = vector_build(4, (double)1, (double)j, (double)m->m, (double)j);
	extracted = (t_vec *)matrix_get_submatrix(m, temp);
	vector_destroy(temp);
	return (extracted);
}

t_mat	*matrix_get_line(t_mat *m, int i)
{
	t_vec	*range;
	t_mat	*line;

	range = vector_build(4, (double)i, 1.0, (double)i, (double)m->n);
	line = matrix_get_submatrix(m, range);
	vector_destroy(range);
	return (line);
}

t_vec	*matrix_get_line_transposed(t_mat *m, int i)
{
	t_mat	*linet;

	linet = matrix_get_line(m, i);
	linet = matrixx(linet, matrix_transpose(linet));
	return ((t_vec *)linet);
}

t_mat	*matrix_new_mn(int m, int n)
{
	t_mat	*mnmn;

	mnmn = matrix_new();
	mnmn->m = m;
	mnmn->n = n;
	return (mnmn);
}

t_mat	*matrix_copy(t_mat *a)
{
	t_mat	*mcp;

	mcp = matrix_new_mn(a->m, a->n);
	mcp->i = lstdbl_copy(a->i);
	return (mcp);
}
