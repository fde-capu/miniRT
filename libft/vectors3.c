/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:55:25 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/15 16:36:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	vector_get_element(t_vec *vec, int i)
{
	return (matrix_get_element(vec, i, 1));
}

void	vector_put_element(t_vec *vec, int pos, double d)
{
	int		c;
	t_dbl	*h;

	h = vec->i;
	c = 1;
	while (c < pos)
	{
		h = h->nx;
		c++;
	}
	h->d = d;
	return ;
}

t_vec	*matvec_get_element(t_mvec *mv, int i, int j)
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

int		vector_range_check_boundaries(t_vec *range, t_mat *m)
{
	int	i1;
	int	i2;
	int	j1;
	int	j2;

	i1 = vector_get_element(range, 1);
	i2 = vector_get_element(range, 3);
	j1 = vector_get_element(range, 2);
	j2 = vector_get_element(range, 4);
	if ((i1 <= 0) || (j1 <= 0) || (i2 > m->m) || (i2 > m->n))
		return (0);
	return (1);
}

void	vector_range_fix(t_vec *range)
{
	int	i1;
	int	i2;
	int	j1;
	int	j2;

	i1 = vector_get_element(range, 1);
	i2 = vector_get_element(range, 3);
	j1 = vector_get_element(range, 2);
	j2 = vector_get_element(range, 4);
	if (i2 < i1)
	{
		vector_put_element(range, 1, i2);
		vector_put_element(range, 3, i1);
	}
	if (j2 < j1)
	{
		vector_put_element(range, 2, j2);
		vector_put_element(range, 4, j1);
	}
	return ;
}
