/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:48:36 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/17 13:05:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*stc_skip_c(char *s, char c)
{
	while ((*s) && (*s == c))
		s++;
	return (s);
}

static int	stc_count(char *s, char c)
{
	int	n;

	n = 0;
	s = stc_skip_c((char *)s, c);
	if ((*s) && (*s != c))
		n++;
	while ((*s) && (*s != c))
		s++;
	return (*s ? n + stc_count(s, c) : n);
}

static int	stc_len(char *s, char c)
{
	int	n;

	n = 0;
	while ((*s) && (*s != c))
	{
		s++;
		n++;
	}
	return (n);
}

char		**ft_split(char const *s, char c)
{
	char	**spl;
	char	*z;
	int		i;
	int		w;

	z = (char *)s;
	spl = (char **)ft_calloc(sizeof(char *) * (stc_count(z, c) + 1), 1);
	if (!spl)
		return (0);
	i = 0;
	z = stc_skip_c(z, c);
	while (*z)
	{
		spl[i] = (char *)ft_calloc(stc_len(z, c) + 1, 1);
		if (!spl[i])
			return (0);
		w = 0;
		while ((*z) && (*z != c))
			spl[i][w++] = *z++;
		i++;
		z = stc_skip_c(z, c);
	}
	return (spl);
}
