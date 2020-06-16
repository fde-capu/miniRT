/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:24:42 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/16 08:35:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	r;

	if ((!s) || (!*s))
		return (0);
	r = 0;
	while (*(s + r))
		r++;
	return (r);
}

size_t	ft_strarrlen(char **s)
{
	size_t	l;

	l = 0;
	while ((s[l]) && (*s[l]))
		l++;
	return (l);
}
