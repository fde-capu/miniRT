/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:36:23 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/27 14:38:55 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (!n)
		return (0);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while ((*a) && (*b) && (*a == *b) && (--n > 0))
	{
		a++;
		b++;
	}
	return (*a - *b);
}
