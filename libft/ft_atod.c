/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:53:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/10 17:11:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	char	*n;
	int		lod;
	int		rod;
	double	dec;
	char	*snc;

	if ((!str) || (!*str))
		return (0.0);
	n = ft_strdup(str);
	lod = ft_atoi(n);
	snc = ft_check(n, "-?[0123456789]*\\.");
	if (snc)
	{
		rod = ft_atoi(ft_isdigit(*(snc)) ? snc : 0);
		dec = (double)rod / (ft_pow2(10, ft_countdigits(rod)));
	}
	else
		dec = 0;
	free(n);
	dec += lod;
	dec *= *str == '-' ? -1 : 1;
	return (dec);
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
			ft_lstdbl_addlast(vec->i, d);
		h += *h == ',' ? 1 : 0;
		s = h;
		n++;
	}
	vec->m = 1;
	vec->n = n;
	return (vec);
}
