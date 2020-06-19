/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrinset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:24:15 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/18 15:02:29 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrinset(char r, char const *sset)
{
	char	*s;

	s = (char *)sset;
	while ((s) && (*s))
	{
		if (*s == r)
			return (1);
		s++;
	}
	return (0);
}

int		ft_strchrinset(char *t, char const *sset)
{
	return (ft_chrinset(*t, sset));
}

int		ft_chrsame(char a, char b)
{
	if (!a && !b)
		return (1);
	if (!a || !b)
		return (0);
	return (a == b ? 1 : 0);
}
