/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 12:41:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/19 14:50:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_insp_count(char *h, char x)
{
	int		i;

	i = 1;
	while (*h)
	{
		i += *h == x ? 1 : 0;
		h = ft_inskip(h);
	}
	return (i);
}

static int	insp_len(char *h, char x)
{
	char	*h2;

	h2 = h;
	while (*h2)
	{
		if (*h2 == x)
			break ;
		h2 = ft_inskip(h2);
	}
	return (h2 - h);
}

char		**ft_insplit(const char *str, char x)
{
	int		i;
	int		c;
	char	**spl;
	int		l;
	char	*h;

	h = (char *)str;
	c = ft_insp_count(h, x);
	spl = (char **)ft_calloc(sizeof(char *) * (c + 1), 1);
	if (!spl)
		return (0);
	i = 0;
	while (i < c)
	{
		l = insp_len(h, x);
		spl[i] = (char *)ft_calloc(l + 1, 1);
		if (!spl[i])
			return (0);
		ft_strlcpy(spl[i], h, l + 1);
		i++;
		h += l + 1;
	}
	return (spl);
}
