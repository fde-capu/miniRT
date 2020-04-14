/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 03:12:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/01/28 16:07:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cm;
	char	*w;
	char	*r;

	cm = malloc(ft_strlen(s1) + 1);
	if (!cm)
		return (NULL);
	w = cm;
	r = (char *)s1;
	while (*r)
	{
		*w = *r;
		w++;
		r++;
	}
	*w = 0;
	return (cm);
}
