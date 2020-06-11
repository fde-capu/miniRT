/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:48:36 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/29 09:10:10 by fde-capu         ###   ########.fr       */
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
		return (NULL);
	i = 0;
	z = stc_skip_c(z, c);
	while (*z)
	{
		spl[i] = (char *)ft_calloc(stc_len(z, c) + 1, 1);
		if (!spl[i])
			return (NULL);
		w = 0;
		while ((*z) && (*z != c))
			spl[i][w++] = *z++;
		i++;
		z = stc_skip_c(z, c);
	}
	return (spl);
}
