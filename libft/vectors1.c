/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:46:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/13 09:52:00 by fde-capu         ###   ########.fr       */
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
	vec->i = ft_lstdbl_new(va_arg(ap, double));
	vec->m = 1;
	vec->n = 1;
	while (len--)
	{
		d = va_arg(ap, double);
		ft_lstdbl_addlast(vec->i, d);
		vec->n++;
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
	int		argc;

	mat = ft_calloc(sizeof(t_mat), 1);
	va_start(ap, m);
	mat->i = ft_lstdbl_new(va_arg(ap, double));
	argc = 0;
	while ((d = va_arg(ap, double)))
	{
		argc++;
		ft_lstdbl_addlast(mat->i, d);
	}
	va_end(ap);
	mat->m = m;
	mat->n = ft_ceil((double)argc / (double)m);
	return (mat);
}

t_mvec	*matvec_new(void)
{
	t_mvec	*mvec;

	mvec = ft_calloc(sizeof(t_mvec), 1);
	return (mvec);
}
