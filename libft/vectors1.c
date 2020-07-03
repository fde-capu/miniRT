/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:46:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/03 17:49:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vec_destroy(t_vec *vec)
{
	ft_mat_destroy((t_mat *)vec);
	return ;
}

t_vec	*ft_vec(int len, ...)
{
	va_list	ap;
	t_vec	*vec;
	double	d;

	va_start(ap, len);
	vec = ft_calloc(sizeof(t_vec), 1);
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
	vec = ft_calloc(sizeof(t_vec), 1);
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

t_mvec	*ft_mvec(void)
{
	t_mvec	*mvec;

	mvec = ft_calloc(sizeof(t_mvec), 1);
	return (mvec);
}

void	ft_vm_add(t_mvec *mv, int i, int j, t_vec *vec)
{
	t_vec	*h;

	h = ft_vm(mv, i, j);
	if (h->pv)
	{
		vec->pv = h->pv;
		vec->nx = h->nx;
		vec->pv->nx = vec;
		ft_vec_destroy(h);
	}
	else
	{
		vec->pv = 0;
		vec->nx = mv->i->nx;
		mv->i = ft_vecx(mv->i, vec);
	}
	return ;
}
