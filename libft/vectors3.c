/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:55:25 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 16:51:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	matrix_get_element(t_mat *mat, int m, int n)
{
	t_dbl	*h;

	if (!mat->i)
		return (0);
	h = matrix_goto_element(mat, m, n);
	return (h ? h->d : 0);
}

double	vector_get_element(t_vec *vec, int i)
{
	return (matrix_get_element(vec, i, 1));
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

void	matrix_put_element(t_mat *dst, int i, int j, double d)
{
	matrix_goto_element(dst, i, j)->d = d;
	return ;
}

void	matrix_put_matrix(t_mat *dest, t_mat *ref, int i, int j)
{
	t_mat	*scrn;
	int		x;
	int		y;

	scrn = matrix_empty(4, 4);
	x = 1;
	while (x <= 1)
	{
		y = 1;
		while (y <= j)
		{
			matrix_put_element(scrn, i + x - 1, j + y - 1,
				matrix_get_element(ref, x, y));
			y++;
		}
		x++;
	}
	matrix_screen(dest, scrn);
	matrix_destroy(scrn);
	return ;
}
