/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:21:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/11 15:29:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns allocated unsigned int to char *.
*/

char	*ft_uitoa(unsigned int n)
{
	unsigned int	len;
	char			*w;
	long			t;
	char			*r;

	t = (long)n;
	len = 1;
	while (t /= 10)
		len++;
	r = ft_calloc(sizeof(char) * (len + 1), 1);
	if (!r)
		return (NULL);
	w = r + len;
	*w-- = 0;
	*w = '0';
	if (!n)
		return (r);
	t = (long)n * 10;
	while (t /= 10)
		*w-- = (t % 10) + '0';
	return (r);
}
