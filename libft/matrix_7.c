/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:00:24 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/01 16:00:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
