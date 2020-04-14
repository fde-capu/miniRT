/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_ibase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:28:36 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 16:29:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_countdigits_ibase(long long number, unsigned int base)
{
	long long	c;

	c = number >= 0 ? 1 : 2;
	number = ft_abs(number);
	while (number > base)
	{
		c++;
		number /= base;
	}
	return (c);
}
