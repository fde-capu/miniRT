/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 03:21:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/10 09:09:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*d;
	char	*s;
	size_t	a;
	size_t	r;

	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	r = ft_strlen(dst) + ft_strlen(src);
	d = (char *)dst;
	s = (char *)src;
	a = dstsize;
	while ((*d) && (--a))
		d++;
	a = dstsize - ft_strlen(dst) - 1;
	while ((a--) && (*s))
	{
		*d = *s;
		d++;
		s++;
	}
	*d = 0;
	return (r);
}
