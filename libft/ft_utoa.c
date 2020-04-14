/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:21:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/20 19:21:18 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(unsigned long n)
{
	unsigned int		len;
	char				*w;
	unsigned long		t;
	char				*r;

	t = n;
	len = 1;
	while (t /= 10)
		len++;
	r = ft_calloc(sizeof(char) * (len + 1), 1);
	if (!r)
		return (NULL);
	w = r + len;
	*w-- = 0;
	*w = '0';
	if (!n)
		return (r);
	t = n;
	while (t)
	{
		*w-- = (t % 10) + '0';
		t /= 10;
	}
	return (r);
}
