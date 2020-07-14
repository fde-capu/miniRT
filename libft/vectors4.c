/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:15:00 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 17:04:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl	*matrix_goto_element(t_mat *mat, int m, int n)
{
	t_dbl	*h;
	int		c;

	h = mat->i;
	c = (n - 1) * mat->m + m;
	while (--c)
		h = h->nx;
	return (h);
}

void	vector_normalize(t_vec *mv)
{
	double	d;
	t_dbl	*h;
	double	mag;

	mag = vector_magnitude(mv);
	d = 0;
	h = mv->i;
	while (h)
	{
		h->d /= mag;
		h = h->nx;
	}
	return ;
}

int		is_normalized(t_vec *vec)
{
	return (vector_magnitude(vec) == 1 ? 1 : 0);
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

void	matrix_screen(t_mat *dst, t_mat *src)
{
	int		i;
	int		j;
	double	d;

	i = 1;
	while (i <= dst->m)
	{
		j = 1;
		while (j <= dst->n)
		{
			if ((d = matrix_get_element(src, i, j)))
				matrix_put_element(dst, i, j, d);
			j++;
		}
		i++;
	}
	return ;
}
