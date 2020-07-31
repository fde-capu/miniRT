/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:46:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/31 11:56:28 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vector_destroy(t_vec *vec)
{
	matrix_destroy((t_mat *)vec);
	return ;
}

t_vec	*vector_build(int len, ...)
{
	va_list	ap;
	t_vec	*vec;
	double	d;

	va_start(ap, len);
	vec = ft_calloc(sizeof(t_vec), 1);
	vec->n = 1;
	vec->m = 0;
	while (len--)
	{
		d = va_arg(ap, double);
		vec->i = lstdbl_addlast(vec->i, d);
		vec->m++;
	}
	va_end(ap);
	return (vec);
}

t_mat	*matrix_new(void)
{
	t_mat	*mat;

	mat = ft_calloc(sizeof(t_mat), 1);
	return (mat);
}

t_mat	*matrix_build(int m, ...)
{
	va_list	ap;
	t_mat	*mat;
	double	d;

	mat = matrix_new();
	va_start(ap, m);
	mat->m = m;
	while ((m--) && (d = va_arg(ap, double)))
		mat->i = lstdbl_addlast(mat->i, d);
	va_end(ap);
	mat->n = ft_ceil((double)mat->m / (double)m);
	return (mat);
}

t_mvec	*matvec_new(void)
{
	t_mvec	*mvec;

	mvec = ft_calloc(sizeof(t_mvec), 1);
	return (mvec);
}
