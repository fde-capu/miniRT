/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:18:41 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 12:14:34 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*st_trimstart(char const *s1, char const *set)
{
	char	*r;

	r = (char *)s1;
	while ((*r) && (ft_chrinset(r, set)))
		r++;
	return (r);
}

static size_t	st_trimlen(char const *s1, char const *set)
{
	size_t	l;
	char	*r;

	r = st_trimstart(s1, set);
	l = 0;
	while (*r)
	{
		r++;
		l++;
	}
	r--;
	while ((l) && (ft_chrinset(r, set)))
	{
		r--;
		l--;
	}
	return (l);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*m;
	size_t	l;
	char	*w;
	char	*r;

	l = st_trimlen(s1, set);
	m = ft_calloc(l + 1, 1);
	if (!m)
		return (NULL);
	w = m;
	r = st_trimstart(s1, set);
	while ((l) && (*r))
	{
		*w = *r;
		w++;
		r++;
		l--;
	}
	return (m);
}

char			*ft_strtrimx(char *s1, char *set)
{
	char	*trd;

	trd = ft_strtrim(s1, set);
	free(s1);
	return (trd);
}

char			*ft_trim(char *str)
{
	return (ft_strtrimx(str, TRIM_SET));
}
