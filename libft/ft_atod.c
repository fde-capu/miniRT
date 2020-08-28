/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:53:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/28 02:59:07 by fde-capu         ###   ########.fr       */
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
	if (!(afterdot = ft_check(str, "[\\-\\+0123456789]*\\.")))
		return ((double)integer);
	digits_count = ft_check(afterdot, "[0123456789]*") - afterdot;
	if (!digits_count)
		return ((double)integer);
	if (digits_count > DOUBLE_PRECISION)
	{
		*(afterdot + DOUBLE_PRECISION) = 0;
		digits_count = DOUBLE_PRECISION;
	}
	digits = (double)ft_atoi(afterdot);
	digits /= ft_pow(10, digits_count);
	if (integer >= 0)
		digits = (double)integer + digits;
	else
		digits = (double)integer - digits;
	return (digits);
}
