/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:46:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/11 16:58:06 by fde-capu         ###   ########.fr       */
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

t_mat	*vector_transpose(t_vec *v)
{
	return (matrix_transpose((t_mat *)v));
}

t_mvec	*matvec_new(void)
{
	t_mvec	*mvec;

	mvec = ft_calloc(sizeof(t_mvec), 1);
	mvec->n = 1;
	return (mvec);
}

int		vector_equal(t_vec *a, t_vec *b)
{
	t_dbl	*ha;
	t_dbl	*hb;

	if (a->m != b->m || a->n != b->n)
		return (0);
	ha = a->i;
	hb = b->i;
	while (ha)
	{
		if (ha->d != hb->d)
			return (0);
		ha = ha->nx;
		hb = hb->nx;
	}
	return (1);
}
