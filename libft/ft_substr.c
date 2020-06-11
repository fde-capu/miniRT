/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:34:24 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/11 15:29:41 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns allocated substring, keeps original as is.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*guy;
	size_t	i;

	guy = malloc(len + 1);
	if (!guy)
		return (NULL);
	if (ft_strlen(s) < start + len - 1)
		len = 0;
	guy[len] = 0;
	i = 0;
	while (len--)
	{
		guy[i] = s[start + i];
		i++;
	}
	return (guy);
}
