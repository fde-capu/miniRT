/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 12:41:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/17 15:39:21 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	insp_count(const char *str, char x, char e)
{
	int		i;
	char	*h;
	char	io[2];
	
	ft_enclosure(io, e);
	i = 1;
	h = (char *)str;
	while ((*h) && (*h != io[1]))
	{
		if (*h == x)
			i++;
		h = ft_inskip(h) ? ft_inskip(h) : h;
		h++;
	}
	return (i);
}

static int	insp_len(char *h, char x, char e)
{
	char	*h2;
	char	io[2];
	
	ft_enclosure(io, e);
	h2 = h;
	while ((*h2) && (*h2 != x) && (*h2 != io[1]))
	{
		h2 = ft_inskip(h2) ? ft_inskip(h2) : h2;
		h2++;
	}
	return (h2 - h);
}

char		**ft_insplit(const char *str, char x)
{
	int		i;
	int		c;
	char	**spl;
	char	*h;
	int		l;

	h = (char *)str + 1;
	c = insp_count(h, x, *str);
//	DEBINT("c", c);
	spl = (char **)ft_calloc(sizeof(char *) * (c + 1), 1);
	if (!spl)
		return (0);
	i = 0;
	while (i < c)
	{
		l = insp_len(h, x, *str);
		spl[i] = (char *)ft_calloc(l + 1, 1);
		if (!spl[i])
			return (0);
		ft_strlcpy(spl[i], h, l + 1);
//		DEBSTR("spl", spl[i]);
		i++;
		h += l + 1;
	}
	return (spl);
}
