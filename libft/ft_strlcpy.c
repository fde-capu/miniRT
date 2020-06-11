/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:05:18 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/29 08:12:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*d;
	char	*s;
	size_t	sz;

	if (!dstsize)
		return (ft_strlen(src));
	d = (char *)dst;
	s = (char *)src;
	sz = dstsize;
	while ((*s) && (sz))
	{
		*d++ = *s++;
		sz = sz > 0 ? sz - 1 : 0;
	}
	if (!sz)
		*(d - 1) = 0;
	else
		*d = 0;
	return (ft_strlen(src));
}
