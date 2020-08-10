/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:31:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/10 12:39:56 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_abs(long long value)
{
	return (value < 0 ? value * (long long)-1 : value);
}

double		ft_abs_double(double value)
{
	return (value < 0 ? value * (double)-1 : value);
}
