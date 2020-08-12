/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:00:24 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/12 08:52:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat	*matrix_new(void)
{
	t_mat	*mat;

	mat = ft_calloc(sizeof(t_mat), 1);
	return (mat);
}

t_mat	*matrix_build(int m, int n, ...)
{
	va_list	ap;
	t_mat	*mat;
	int		c;

	mat = matrix_new();
	va_start(ap, n);
	mat->m = m;
	mat->n = n;
	c = m * n;
	while (c--)
		mat->i = lstdbl_addlast(mat->i, va_arg(ap, double));
	va_end(ap);
	return (mat);
}

t_mat	*matrix_of_vectors_transposed(t_vec *v1, t_vec *v2, t_vec *v3)
{
	t_mat	*foo;
	t_mat	*movt;

	movt = matrix_empty(3, 3);
	foo = vector_transpose(v1);
	matrix_put_matrix(movt, foo, 1, 1);
	foo = vectorx(foo, vector_transpose(v2));
	matrix_put_matrix(movt, foo, 2, 1);
	foo = vectorx(foo, vector_transpose(v3));
	matrix_put_matrix(movt, foo, 3, 1);
	matrix_destroy(foo);
	return (movt);
}

void	matrix_put_vector(t_mat *dst, t_vec *vec, int n)
{
	return (matrix_put_matrix(dst, (t_mat *)vec, 1, n));
}
