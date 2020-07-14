/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ops1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:11:49 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 11:55:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	matrix_determinant(t_mat *a)
{
	int		mult;
	int		c;
	double	det;

	if (a->m != a->n)
		return (0);
	if (a->n == 1)
		return (a->i->d);
	c = 1;
	mult = 1;
	det = 0;
	while (c <= a->n)
	{
		det += mult * (matrix_get_elem(a, 1, c)
			* matrix_determinant(matrix_minor(a, 1, c)));
		c++;
		mult *= -1;
	}
	return (det);
}

t_mat	*matrix_minor(t_mat *a, int i, int j)
{
	t_mat	*new;
	int		m;
	int		n;

	new = ft_calloc(sizeof(t_mat), 1);
	m = 1;
	while (m <= a->m)
	{
		n = 1;
		while (n <= a->n)
		{
			if ((m != i) && (n != j))
			{
				new->i = !new->i ? \
					lstdbl_new(matrix_get_elem(a, i, j)) : \
					lstdbl_addlast(new->i, matrix_get_elem(a, i, j));
			}
			n++;
		}
		m++;
	}
	new->m = a->m - 1;
	new->n = a->n - 1;
	return (new);
}

t_mat	*matrix_sum(t_mat *a, t_mat *b)
{
	t_mat	*new;
	int		c;

	if ((a->m != b->m) || (a->n != b->n))
		return (0);
	new = matrix_build(a->m, a->i->d + b->i->d);
	new->n = a->n;
	c = 2;
	while (c++ <= new->m * new->n)
		lstdbl_addlast(new->i, a->i->d + b->i->d);
	return (new);
}

t_vec	*vector_sum(t_vec *a, t_vec *b)
{
	return ((t_vec *)matrix_sum((t_mat *)a, (t_mat *)b));
}
