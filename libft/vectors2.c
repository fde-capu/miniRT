/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 08:04:00 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/03 17:53:51 by fde-capu         ###   ########.fr       */
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

t_vec	*ft_vecx(t_vec *old, t_vec *new)
{
	ft_vec_destroy(old);
	return (new);
}

void	ft_mat_destroy(t_mat *mat)
{
	if (!mat)
		return ;
	ft_lstdbl_destroy(mat->i);
	free(mat);
	return ;
}

void	ft_mvec_destroy(t_mvec *mat)
{
	t_vec	*h;
	t_vec	*n;

	if (!mat)
		return ;
	h = mat->i;
	n = h->nx;
	while (n)
	{
		ft_vec_destroy(h);
		h = n;
		n = n->nx;
	}
	ft_vec_destroy(h);
	return ;
}

t_vec	*ft_vm(t_mvec *mv, int i, int j)
{
	t_vec	*h;
	t_vec	*p;
	int		c;
	int		d;

	if (i <= 0 || j <= 0)
		return (0);
	if (i > mv->m)
		mv->m = i;
	if (j > mv->n)
		mv->n = j;
	c = 1;
	d = 1;
	h = mv->i;
	if (!h)
	{
		h = ft_calloc(sizeof(t_vec), 1);
		mv->i = h;
	}
	while ((c < i) || (d < j))
	{
		if (!h->nx)
			h->nx = ft_calloc(sizeof(t_vec), 1);
		p = h;
		h = h->nx;
		h->pv = p;
		c++;
		if (c > mv->m)
		{
			c = 1;
			d++;
		}
	}
	return (h);
}
