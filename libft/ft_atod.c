/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:53:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/31 13:45:00 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

double	ft_atod(const char *str)
{
	double	d;
	char	*h;
	int		n[2];

	n[0] = ft_atoi(str);
	if (!(h = ft_strstr(str, ".")))
		return ((double)n[0]);
	n[1] = ft_atoi(h + 1);
}

char	*ft_vtoa(t_vec *vec)
{
	char	*o;
	t_dbl	*h;

	o = ft_strnew();
	h = vec->i;
	while (h)
	{
		o = ft_strcatx(o, ft_dtoa(h->d));
		h = h->nx;
		if (h)
			o = ft_strcatxl(o, ",");
	}
	return (o);
}

t_vec	*ft_atov(char *str)
{
	t_vec	*vec;
	char	*h;
	char	*s;
	double	d;
	int		n;

	h = str;
	s = str;
	vec = 0;
	n = 0;
	while ((*h) && (h = ft_check(h, REG_DOUBLE)))
	{
		d = ft_atod(s);
		if (!vec)
			vec = vector_build(1, d);
		else
			lstdbl_addlast(vec->i, d);
		h += *h == ',' ? 1 : 0;
		s = h;
		n++;
	}
	vec->m = 1;
	vec->n = n;
	return (vec);
}
