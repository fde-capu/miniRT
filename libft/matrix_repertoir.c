/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_repertoir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:25:56 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 16:52:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

t_vec	*matrix_vector_multiply(t_mat *left, t_vec *right)
{
	t_vec	*vec;
	int		i;
	int		j;
	double	d;

	vec = vector_new();
	i = 1;
	while (i <= left->m)
	{
		d = 0;
		j = 1;
		while (j <= right->m)
		{
			d += (vector_get_element(right, j)
				* matrix_get_element(left, i, j));
			j++;
		}
		vec->i = lstdbl_addlast(vec->i, d);
		i++;
	}
	vec->m = right->m;
	vec->n = right->n;
	return (vec);
}

t_vec	*vector_translate(t_vec *vec, t_vec *xyz)
{
	t_mat	*map;
	t_vec	*translated;

	map = matrix_identity(4);
	matrix_put_matrix(map, (t_mat *)xyz, 1, 4);
	translated = matrix_vector_multiply(map, vec);
	return (translated);
}

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
