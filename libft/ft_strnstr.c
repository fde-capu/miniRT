/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:34:40 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/16 16:27:55 by fde-capu         ###   ########.fr       */
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

char		*ft_strstr(const char *a, const char *b)
{
	return (ft_strnstr(b, a, ft_strlen(b)));
}
