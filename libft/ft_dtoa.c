/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:16:37 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/03 07:17:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(double d)
{
	char	*o;

	o = ft_itoa((int)d);
	d -= (int)d;
	d *= DOUBLE_PRECISION;
	o = ft_strcatxl(o, DECIMAL_POINT);
	if (d < 0)
	{
		d *= -1;
		o = ft_strcatx(o, ft_itoa(d));
		o = ft_strcatxr("-", o);
	}
	else
		o = ft_strcatx(o, ft_itoa(d));
	return (o);
}
