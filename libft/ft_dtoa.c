/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:16:37 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/11 10:36:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(double d)
{
	char	*a;
	double	d2;
	int		i;
	int		neg;

	neg = d < 0 ? 1 : 0;
	d *= neg ? -1 : 1;
	a = ft_strcatxl(ft_itoa((int)d), DECIMAL_POINT);
	i = 1;
	d2 = d - (int)d;
	while ((!(int)(d2 *= 10)) && (i++ < DOUBLE_PRECISION_DTOA))
		a = ft_strcatxl(a, "0");
	a = ft_strcatx(a, ft_itoa(d2 * ft_pow(10, (DOUBLE_PRECISION_DTOA - i))));
	a = ft_strcatxr(neg ? "-" : " ", a);
	return (a);
}
