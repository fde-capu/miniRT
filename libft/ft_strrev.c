/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:24:29 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/11 15:29:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns allocated reversed string.
*/

char	*ft_strrev(char *src)
{
	char	*dst;
	char	*p;
	int		r;

	dst = ft_calloc(ft_strlen(src) + 1, 1);
	p = dst;
	r = ft_strlen(src);
	while (r)
	{
		*p = src[r - 1];
		p++;
		r--;
	}
	return (dst);
}
