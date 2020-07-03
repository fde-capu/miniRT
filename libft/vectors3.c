/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:55:25 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/03 18:03:05 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

t_vec	*ft_vm(t_mvec *mv, int i, int j)
{
	t_vec	*h;
	t_vec	*p;
	int		c;
	int		d;

	if (i <= 0 || j <= 0)
		return (0);
	mv->m = i > mv->m ? i : mv->m;
	mv->n = j > mv->n ? j : mv->n;
	c = 1;
	d = 1;
	h = mv->i ? mv->i : ft_calloc(sizeof(t_vec), 1);
	mv->i = mv->i ? mv->i : h;
	while ((c < i) || (d < j))
	{
		if (!h->nx)
			h->nx = ft_calloc(sizeof(t_vec), 1);
		p = h;
		h = h->nx;
		h->pv = p;
		d = c + 1 > mv->m ? d + 1 : d;
		c = c + 1 > mv->m ? 1 : c + 1;
	}
	return (h);
}
