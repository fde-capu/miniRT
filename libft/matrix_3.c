/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:00:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 15:24:56 by fde-capu         ###   ########.fr       */
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

t_mat	*matrix_checkers_sign(t_mat *a)
{
	t_mat	*chk;
	int		i;
	int		mtn;

	chk = matrix_copy(a);
	mtn = a->m * a->n;
	i = 1;
	while (i <= mtn)
	{
		if (!(i % 2))
			lstdbl_mult_element(chk->i, i, -1);
		i++;
	}
	return (chk);
}

t_mat	*matrix_of_cofactors(t_mat *a)
{
	t_mat	*moc;

	if (a->m != a->n)
		ft_die(COFACTORERR, ERRCOFACTOR);
	moc = matrix_of_minors(a);
	moc = matrixx(moc, matrix_checkers_sign(a));
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
