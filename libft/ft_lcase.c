/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:27:32 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 16:27:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lcase(char *str)
{
	char	*dst;
	int		i;

	dst = ft_calloc(ft_strlen((const char *)str) + 1, 1);
	i = 0;
	while (str[i])
	{
		dst[i] = ft_tolower(str[i]);
		i++;
	}
	return (dst);
}
