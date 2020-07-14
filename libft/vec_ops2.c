/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ops2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 08:29:00 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 12:58:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat	*matrix_inverse(t_mat *a)
{
	t_mat	*mt;
	double	det;

	mt = matrix_of_minors(a);
	mt = ft_x(mt, matrix_of_cofactors(mt));
	mt = ft_x(mt, matrix_transpose(mt));
	det = matrix_determinant(a);
	mt = ft_x(mt, matrix_multiply_scalar(mt, 1 / det));
	return (mt);
}

/*
** matrix_switch_elem
** Would it be sane in performance only switching pointers?
*/

void	matrix_switch_elem(t_mat *mat, t_vec *tvec)
{
	t_dbl	*ha;
	t_dbl	*hb;
	double	a;
	double	b;

	ha = mat->i;
	while (loop_2d(vector_get_elem(tvec, 1), vector_get_elem(tvec, 2)))
		ha = ha->nx;
	a = ha->d;
	hb = mat->i;
	while (loop_2d(vector_get_elem(tvec, 3), vector_get_elem(tvec, 4)))
		hb = hb->nx;
	b = hb->d;
	ha->d = b;
	hb->d = a;
	return ;
}

t_mat	*matrix_multiply_scalar(t_mat *mat, double s)
{
	t_mat	*mms;
	t_dbl	*ld;

	mms = matrix_copy(mat);
	ld = mms->i;
	while (loop_2d(mat->m, mat->n))
	{
		ld->d *= s;
		ld = ld->nx;
	}
	return (mms);
}

t_mat	*matrix_transpose(t_mat *a)
{
	t_mat	*mt;
	int		i;
	int		j;
	int		mndbt;
	t_vec	*tvec;

	mt = matrix_copy(a);
	mndbt = a->m * a->n / 2;
	i = 1;
	while (i <= a->m)
	{
		j = 1;
		while (j <= a->n)
		{
			if (i != j)
			{
				tvec = vector_build(4, i, j, j, i);
				matrix_switch_elem(a, tvec);
				free(tvec);
			}
			j++;
		}
		i++;
	}
	return (mt);
}

t_mat	*matrix_of_cofactors(t_mat *a)
{
	t_mat	*moc;
	int		i;
	int		mtn;

	moc = matrix_copy(a);
	mtn = a->m * a->n;
	i = 1;
	while (i <= mtn)
	{
		if (!(i % 2))
			lstdbl_mult_elem(moc->i, i, -1);
		i++;
	}
	return (moc);
}
