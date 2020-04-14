/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 02:52:58 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/23 03:11:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sc1;
	unsigned char	*sc2;

	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	while (n--)
	{
		if (*sc1++ != *sc2++)
			return (*(sc1 - 1) - *(sc2 - 1));
	}
	return (0);
}
