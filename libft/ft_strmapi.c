/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 02:43:19 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/24 03:00:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r;
	int		l;
	char	*m;
	char	*w;
	int		x;

	l = ft_strlen(s);
	m = malloc(l + 1);
	if (!m)
		return (NULL);
	w = m;
	x = 0;
	r = (char *)s;
	while (*r)
	{
		*w = f(x, *r);
		r++;
		x++;
		w++;
	}
	*w = 0;
	return (m);
}
