/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 22:48:45 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/29 16:05:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*p;

	p = ft_memchr(src, c, n);
	if (p != NULL)
	{
		p = ft_memcpy(dst, src, p - src + 1) + (p - src + 1);
		return (p);
	}
	ft_memcpy(dst, src, n);
	return (NULL);
}
