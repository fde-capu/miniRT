/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:53:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/02 16:52:17 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	char	*afterdot;
	int		integer;
	double	digits;
	int		digits_count;

	integer = ft_atoi(str);
	if (!(afterdot = ft_check(str, "[-+]?[0-9]*\\.")))
		return ((double)integer);
	digits_count = ft_check(afterdot, "[0-9]*") - afterdot;
	if (digits_count > DOUBLE_PRECISION)
		*(afterdot + DOUBLE_PRECISION) = 0;
	digits = (double)ft_atoi(afterdot) / ft_pow(10, digits_count);
	if (integer >= 0)
		return ((double)integer + digits);
	else
		return ((double)integer - digits);
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
			vec->i = lstdbl_addlast(vec->i, d);
		h += *h == ',' ? 1 : 0;
		s = h;
		n++;
	}
	vec->m = n;
	vec->n = 1;
	return (vec);
}
