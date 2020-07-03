/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 08:04:00 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/03 08:05:14 by fde-capu         ###   ########.fr       */
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
