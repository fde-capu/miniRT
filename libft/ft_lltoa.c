/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:27:19 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 16:27:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa(signed long long n)
{
	char				*w;
	unsigned long long	t;
	char				*r;

	t = ft_abs(n);
	r = ft_ultoa(t);
	if (n >= 0)
		return (r);
	w = ft_calloc(ft_strlen(r) + 2, 1);
	w[0] = '-';
	ft_memmove(&w[1], (void *)r, ft_strlen(r));
	return (w);
}
