/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:00:11 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/12 07:37:48 by fde-capu         ###   ########.fr       */
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
	t_mat	*minor;
	int		m;
	int		n;

	minor = ft_calloc(sizeof(t_mat), 1);
	m = 1;
	while (m <= a->m)
	{
		n = 1;
		while (n <= a->n)
		{
			if ((m != i) && (n != j))
			{
				minor->i = !minor->i ? \
					lstdbl_new(matrix_get_element(a, i, j)) : \
					lstdbl_addlast(minor->i, matrix_get_element(a, i, j));
			}
			n++;
		}
		m++;
	}
	minor->m = a->m - 1;
	minor->n = a->n - 1;
	return (minor);
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
