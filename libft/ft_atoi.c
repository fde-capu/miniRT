/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:29:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 12:13:57 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef INT_MAX
# define INT_MAX 2147483647
#endif
#ifndef INT_MIN
# define INT_MIN -2147483648
#endif

static int	st_sum_dign(char *a)
{
	int	s;

	s = 0;
	while (ft_isdigit(*a))
	{
		s++;
		a++;
	}
	return (s);
}

long long	ft_atoi(const char *str)
{
	char		*a[3];
	int			l;
	long long	r;

	if ((!str) || (!*str))
		return (0);
	a[0] = ft_strtrim((char *)str, TRIM_SET);
	a[1] = a[0];
	a[1] += *a[1] == '-' || *a[1] == '+' ? 1 : 0;
	a[2] = a[1];
	l = 0 + st_sum_dign(a[1]);
	a[1] += st_sum_dign(a[1]);
	r = 0;
	a[1] = a[2];
	while ((l--) && (ft_isdigit(*a[1])))
	{
		r += (*a[1]++ - '0');
		if (((*a[0] != '-') && (r > INT_MAX)) || ((*a[0] == '-')
			&& (r * -1 < INT_MIN)))
			return (*a[0] != '-' ? -1 : 0);
		r *= l ? 10 : 1;
	}
	r *= *a[0] == '-' ? -1 : 1;
	free(a[0]);
	return (r);
}
