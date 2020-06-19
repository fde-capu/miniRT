/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inskip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 09:16:45 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/19 14:24:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_inskip :: is fairly uncomplete.
** does not take account for sub-skips such as "" or ''.
*/

char	*ft_inskip(char *h)
{
	char	io[2];

	if (!ft_enclosure(io, *h))
	{
		if (*h && *h == '\\')
			return (h + 2);
		if (*h)
			return (h + 1);
		else
			return (0);
	}
	if (*h == io[0])
	{
		h++;
		while (*h && (*h != io[1]))
			h = ft_inskip(h);
	}
	return (*h ? h + 1 : 0);
}

char	*ft_inside(char *h)
{
	char	*e;

	e = ft_inskip(h);
	if (e - h == 1)
	{
		if (ft_strnstr(ENCLOSURES, h, 2))
			return (e);
		else
			return (e - 1);
	}
	return (ft_substr(h, 1, e - h - 2));
}

int		ft_enclosure(char *io, char h)
{
	if (ft_chrinset(h, ENCLOSE_OPEN))
	{
		io[0] = *(ft_findstr(ENCLOSURES, h));
		io[1] = *((ft_findstr(ENCLOSURES, h)) + 1);
		return (1);
	}
	return (0);
}
