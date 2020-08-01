/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:46:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/01 13:22:19 by fde-capu         ###   ########.fr       */
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

t_mvec	*matvec_new(void)
{
	t_mvec	*mvec;

	mvec = ft_calloc(sizeof(t_mvec), 1);
	return (mvec);
}
