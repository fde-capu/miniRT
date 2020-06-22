/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:34:40 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/19 11:49:28 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isneedle(char *h, char *n)
{
	while ((*h == *n) && *h)
	{
		h++;
		n++;
	}
	return (*n ? 0 : 1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	int		nl;

	h = (char *)haystack;
	n = (char *)needle;
	if (ft_strlen(n) > ft_strlen(h))
		return (NULL);
	if ((!*n) || ((*n == 0) && (len == 0)) || (needle == haystack))
		return (h);
	nl = 0;
	while (*++n)
		nl++;
	n = (char *)needle;
	while (*h && len)
	{
		if ((isneedle(h, n)) && ((int)len - nl > 0))
			return (h);
		h++;
		len--;
	}
	return (NULL);
}

/*
**	ft_strstr :: twisted version of above.
**  = find (this on this), give me address or nothing'.
*/

char		*ft_strstr(const char *a, const char *b)
{
	return (ft_strnstr(b, a, ft_strlen(b)));
}

int			ft_strbegins(const char *str, const char *beg)
{
	return (ft_strstr(beg, str) == str ? 1 : 0);
}
