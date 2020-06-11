/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:43:29 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 16:31:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_btod_single(char n)
{
	int		r;

	r = (int)ft_tolower(n);
	r -= n >= '0' && n <= '9' ? '0' : 0;
	r -= n >= 'a' && n <= 'z' ? 'a' + 10 : 0;
	return (r);
}

long long		ft_btod(char *nbr, int b_from)
{
	double	e;
	double	v;
	int		c;

	e = 1;
	v = 0;
	c = ft_strlen(nbr) - 1;
	c = c > 0 ? c : 0;
	while (c)
	{
		v += (ft_btod_single(nbr[c]) * e);
		e *= b_from;
		c--;
	}
	return (e);
}
