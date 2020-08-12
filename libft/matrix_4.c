/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:00:11 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/12 13:52:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat	*matrix_inverse(t_mat *a)
{
	t_mat	*mt;
	double	det;

	det = matrix_determinant(a);
	if (!det || a->m != a->n)
		return (0);
	mt = matrix_adjoint(a);
	mt = ft_x(mt, matrix_scalar_multiply(mt, 1.0 / det));
	return (mt);
}

/*
** matrix_screen is thought for equal size matrices.
*/

void	matrix_screen(t_mat *dst, t_mat *src)
{
	int		i;
	int		j;
	double	d;

	i = 1;
	while (i <= dst->m)
	{
		j = 1;
		while (j <= dst->n)
		{
			if ((d = matrix_get_element(src, i, j)))
				matrix_put_element(dst, i, j, d);
			j++;
		}
		i++;
	}
	return ;
}

t_mat	*matrix_minor(t_mat *a, int i, int j)
{
	t_mat	*mat;
	int		ic;
	int		jc;

	mat = matrix_new();
	mat->m = a->m - 1;
	mat->n = a->n - 1;
	jc = 0;
	while (++jc <= a->n)
	{
		ic = 0;
		while (++ic <= a->m)
		{
			if (ic != i && jc != j)
				mat->i = lstdbl_addlast(mat->i, matrix_get_element(a, ic, jc));
		}
	}
	return (mat);
}

double	matrix_get_element(t_mat *mat, int m, int n)
{
	t_dbl	*h;

	if (!mat->i)
		return (0);
	h = matrix_goto_element(mat, m, n);
	return (h ? h->d : 0);
}

t_dbl	*matrix_goto_element(t_mat *mat, int m, int n)
{
	t_dbl	*h;
	int		c;

	h = mat->i;
	c = ((n - 1) * mat->m) + m;
	while (--c)
		h = h->nx;
	return (h);
}
