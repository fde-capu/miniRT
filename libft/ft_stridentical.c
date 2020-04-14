/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stridentical.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:50:46 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/03 15:23:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stridentical(const char *s1, const char *s2)
{
	char	*a;
	char	*b;

	a = (char *)s1;
	b = (char *)s2;
	while (a && b && *a && *b)
	{
		if (*a != *b)
			return (0);
		a++;
		b++;
	}
	return (!*a && !*b ? 1 : 0);
}
