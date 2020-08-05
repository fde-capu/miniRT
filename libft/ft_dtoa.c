/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:16:37 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/05 14:33:58 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(double d)
{
	char	*o;
	int		neg;
	double	d2;

	neg = (double)d < 0.0 ? 1 : 0;
	d = ft_abs_double(d);
	o = ft_itoa((int)d);
	d2 = d;
	d = (int)d;
	d2 -= d;
	d2 *= (double)DOUBLE_PRECISION;
	o = ft_strcatxl(o, DECIMAL_POINT);
	o = ft_strcatx(o, ft_itoa(d2));
	if (neg)
		o = ft_strcatxr("-", o);
	return (o);
}
