/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:59:37 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/07 15:35:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat	*matrix_transpose(t_mat *a)
{
	t_mat	*transposed;
	int		i;
	int		j;
	t_dbl	*h;

	transposed = matrix_new();
	transposed->m = a->n;
	transposed->n = a->m;
	h = a->i;
	i = 1;
	while (i <= a->n)
	{
		j = 1;
		while (j == a->m)
		{
			transposed->i = lstdbl_addlast(transposed->i, h->d);
			h++;
			j++;
		}
		i++;
	}
	return (transposed);
}

t_mat	*matrix_diagonal(t_vec *dvec)
{
	t_mat	*mid;
	int		i;
	int		sts;
	int		sp1;
	int		x;

	x = 1;
	mid = ft_calloc(sizeof(t_mat), 1);
	sts = dvec->m * dvec->m;
	sp1 = dvec->m + 1;
	i = 1;
	while (i <= sts)
	{
		if (i % sp1 == 1)
			mid->i = lstdbl_addlast(mid->i, vector_get_element(dvec, x++));
		else
			mid->i = lstdbl_addlast(mid->i, 0);
		i++;
	}
	mid->m = dvec->m;
	mid->n = dvec->m;
	return (mid);
}

t_mat	*matrix_identity(int s)
{
	t_mat	*mid;
	int		i;
	int		sts;
	int		sp1;

	mid = ft_calloc(sizeof(t_mat), 1);
	sts = s * s;
	sp1 = s + 1;
	i = 1;
	while (i <= sts)
	{
		if (i % sp1 == 1)
			mid->i = lstdbl_addlast(mid->i, 1);
		else
			mid->i = lstdbl_addlast(mid->i, 0);
		i++;
	}
	mid->m = s;
	mid->n = s;
	return (mid);
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

t_mat	*matrix_sum(t_mat *a, t_mat *b)
{
	t_mat	*summed;
	int		c;

	if ((a->m != b->m) || (a->n != b->n))
		return (0);
	summed = matrix_new();
	summed->m = a->m;
	summed->n = a->n;
	c = 1;
	while (c <= summed->m * summed->n)
	{
		summed->i = lstdbl_addlast \
			(summed->i, matrix_get_element(a, c, 1) + matrix_get_element(b, c, 1));
		c++;
	}
	return (summed);
}
