/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:28:21 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/27 14:28:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*r;
	size_t				ns;

	r = (const unsigned char *)s;
	ns = 0;
	while (ns < n)
		if (r[ns] == (unsigned char)c)
			return ((void *)&r[ns]);
		else
			ns++;
	return (NULL);
}
