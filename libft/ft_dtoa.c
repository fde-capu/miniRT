/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:16:37 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/31 13:05:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(double d)
{
	char	*o;
	int		neg;

	neg = (int)d < 0 ? 1 : 0;
	d = ft_abs(d);
	o = ft_itoa((int)d);
	d -= (int)d;
	d *= DOUBLE_PRECISION;
	o = ft_strcatxl(o, DECIMAL_POINT);
	o = ft_strcatx(o, ft_itoa(d));
	if (neg)
		o = ft_strcatxr("-", o);
	return (o);
}
