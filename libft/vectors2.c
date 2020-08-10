/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 08:04:00 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/10 14:18:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	matvec_destroy(t_mvec *mat)
{
	t_vec	*h;
	t_vec	*n;

	if (!mat)
		return ;
	h = mat->i;
	n = h ? h->nx : 0;
	while (n)
	{
		vector_destroy(h);
		h = n;
		n = n->nx;
	}
	vector_destroy(h);
	return ;
}

t_vec	*vectorx(t_vec *old, t_vec *new)
{
	vector_destroy(old);
	return (new);
}

void	matvec_insert_at_pos(t_mvec *mv, int i, int j, t_vec *vec)
{
	t_vec	*h;

	h = matvec_get_element(mv, i, j);
	if (h->pv)
	{
		vec->pv = h->pv;
		vec->nx = h->nx;
		vec->pv->nx = vec;
		vector_destroy(h);
	}
	else
	{
		vec->pv = 0;
		vec->nx = mv->i->nx;
		mv->i = vectorx(mv->i, vec);
	}
	return ;
}

t_vec	*vector_new(void)
{
	t_vec	*vec;

	vec = ft_calloc(sizeof(t_vec), 1);
	vec->m = 1;
	vec->n = 0;
	return (vec);
}
