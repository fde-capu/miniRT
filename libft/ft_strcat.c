/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:18:03 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/04 03:01:00 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(const char *dst, const char *src)
{
	char	*ret;
	char	*r;
	char	*w;

	ret = ft_calloc(ft_strlen(dst) + ft_strlen(src) + 1, 1);
	r = (char *)dst;
	w = (char *)ret;
	while ((r) && (*r))
	{
		*w = *r;
		w++;
		r++;
	}
	r = (char *)src;
	while ((r) && (*r))
	{
		*w = *r;
		w++;
		r++;
	}
	return (ret);
}
