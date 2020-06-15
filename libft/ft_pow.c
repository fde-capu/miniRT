/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:26:30 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 13:13:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
** `ft_pow` is currently not working.
** Use `ft_pow2` instead.
** (Currently only `int a` and posisive int `e`.
*/

double	ft_pow(double a, double e)
{
	double	r;

	if (!e)
		return (1);
	r = e > 0 ? a : 1;
	while ((long long)e)
	{
		r = e < 0 ? r / r : r * r;
		e = e < 0 ? e + 1 : e - 1;
	}
	return (r);
}

double	ft_pow2(double a, double e)
{
	if (e > 1)
		return (a * ft_pow2(a, e - 1));
	if (e == 1)
		return (a);
	return (1);
}
