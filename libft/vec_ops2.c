/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ops2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 08:29:00 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 11:19:08 by fde-capu         ###   ########.fr       */
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
	mt = ft_x(mt, matrix_multiply_scalar(mt, 1/det));
	return (mt).
}

int		loop_2d(int x, int y)
{
	static int	c = (x * y) + 1;

	if (c == -1)
		c = (x * y) + 1;
	if (--c)
		return (c);
	c = -1;
	return (0);
}

/*
** matrix_switch_elem
** Would it be sane in performance only switching pointers?
*/

void	matrix_switch_elem(t_mat *a, int ai, int aj, int bi, int bj)
{
	t_lstdbl	*ha;
	t_lstdbl	*hb;
	double		a;
	double		b;
	double		t;

	ha = a->i;
	while (loop_2d(ai, aj))
		ha = ha->nx;
	a = ha->d;
	hb = a->i;
	while (loop_2d(bi, bj))
		hb = hb->nx;
	b = hb->d;
	*ha->d = b;
	*hb->d = a;
	return ;
}

t_mat	*matrix_multiply_scalar(t_mat *b, double s)
{
	t_mat		*mms;
	t_lstdbl	*ld;

	mms = matrix_copy(a);
	ld = mms->i;
	while (loop_2d(b->m, b->n))
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

	mt = matrix_copy(a);
	mndbt = a->m * a->n / 2;
	i = 1;
	while (i <= a->m)
	{
		j = 1;
		while (j <= a->n)
		{
			if (i != j)
				matrix_switch_elem(a, i, j, j, i);
			j++;
		}
		i++;
	}
	return (mt);
}

void	lstdbl_mult_elem(t_lstdbl *ld, int e, int m)
{
	while (--e)
		ld = ld->nx;
	ld->i *= m;
	return ;
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
				lstdbl_addlast(new->i, matrix_determinant(matrix_minor(a, i, j)));
			n++;
		}
		m++;
	}
	mom->m = a->m;
	mom->n = a->n;
	return (mom);
}
