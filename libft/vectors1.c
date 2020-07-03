/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:46:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/02 14:25:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*ft_vec(int len, ...)
{
	va_list	ap;
	t_vec	*vec;
	double	d;

	va_start(ap, len);
	vec = ft_calloc(sizeof(t_mat), 1);
	vec->i = ft_lstdbl_new(va_arg(ap, double));
	vec->m = 1;
	vec->n = 1;
	while (--len)
	{
		d = va_arg(ap, double);
		ft_lstdbl_addlast(vec->i, d);
		vec->n++;
	}
	va_end(ap);
	return (vec);
}

t_vec	*ft_veci(int len, ...)
{
	va_list	ap;
	t_vec	*vec;
	double	d;

	va_start(ap, len);
	vec = ft_calloc(sizeof(t_mat), 1);
	vec->i = ft_lstdbl_new((double)va_arg(ap, int));
	vec->m = 1;
	vec->n = 1;
	while (--len)
	{
		d = (double)va_arg(ap, int);
		ft_lstdbl_addlast(vec->i, d);
		vec->n++;
	}
	va_end(ap);
	return (vec);
}

t_mat	*ft_mat(int m, ...)
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

double	ft_m(t_mat *mat, int m, int n)
{
	t_dbl	*h;
	int		c;

	if (!mat->i)
		return (0);
	h = mat->i;
	c = (n - 1) * mat->m + m;
	while (--c)
		h = h->nx;
	return (h ? h->d : 0);
}

double	ft_v(t_vec *vec, int i)
{
	return (ft_m(vec, i, 1));
}
