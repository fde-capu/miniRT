/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 03:12:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 10:15:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new;

	new = ft_calloc(ft_strlen(str) + 1, 1);
	if (!new)
		return (NULL);
	ft_strcpy(new, str);
	return (new);
}

char	*ft_strnew(void)
{
	return (ft_strdup(""));
}

char	*ft_str(char *str)
{
	return (ft_strdup(str));
}
