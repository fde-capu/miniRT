/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:26:52 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 16:26:53 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(signed long n)
{
	char			*w;
	unsigned long	t;
	char			*r;

	t = ft_abs(n);
	r = ft_ultoa(t);
	if (n >= 0)
		return (r);
	w = ft_calloc(ft_strlen(r) + 2, 1);
	w[0] = '-';
	ft_memmove(&w[1], (void *)r, ft_strlen(r));
	return (w);
}
