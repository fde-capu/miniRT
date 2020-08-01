/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:00:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/01 16:00:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat	*matrix_empty(int m, int n)
{
	t_mat	*me;

	me = matrix_new();
	me->m = m;
	me->n = n;
	while (loop_2d(m, n))
		me->i = lstdbl_addlast(me->i, 0);
	return (me);
}

t_mat	*matrix_full(int m, int n, double f)
{
	t_mat	*me;

	me = matrix_new();
	me->m = m;
	me->n = n;
	while (loop_2d(m, n))
		me->i = lstdbl_addlast(me->i, f);
	return (me);
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
			lstdbl_mult_element(moc->i, i, -1);
		i++;
	}
	return (moc);
}

/*
** matrix_switch_elements
** Would it be sane in performance only switching pointers?
*/

void	matrix_switch_elements(t_mat *mat, t_vec *tvec)
{
	t_dbl	*ha;
	t_dbl	*hb;
	double	a;
	double	b;

	ha = mat->i;
	while (loop_2d(vector_get_element(tvec, 1), vector_get_element(tvec, 2)))
		ha = ha->nx;
	a = ha->d;
	hb = mat->i;
	while (loop_2d(vector_get_element(tvec, 3), vector_get_element(tvec, 4)))
		hb = hb->nx;
	b = hb->d;
	ha->d = b;
	hb->d = a;
	return ;
}

t_mat	*matrixx(t_mat *old, t_mat *new)
{
	matrix_destroy(old);
	return (new);
}
