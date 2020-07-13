/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:55:25 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/10 17:48:41 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	matrix_get_elem(t_mat *mat, int m, int n)
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

double	vector_get_elem(t_vec *vec, int i)
{
	return (matrix_get_elem(vec, i, 1));
}

t_vec	*matvec_get_elem(t_mvec *mv, int i, int j)
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

double	vector_magnitude(t_vec *v)
{
	double	dp;
	t_dbl	*h;

	h = v->i;
	dp = 0;
	while (h)
	{
		dp += (h->d * h->d);
		h = h->nx;
	}
	dp = (double)sqrt(dp);
	return (dp);
}

void	vector_normalize(t_vec *mv)
{
	// to do
	(void)mv;
	return ;
}

void	matrix_write_matrix(t_mat *dest, int i, int j, t_mat *ref)
{
	// to do
	(void)dest;
	(void)ref;
	(void)i;
	(void)j;
}
