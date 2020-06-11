/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:06:03 by fde-capu          #+#    #+#             */
/*   Updated: 2020/04/22 12:06:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrunc(char *dst, char trunc)
{
	int		i;
	char	*out;

	out = ft_strdup(dst);
	i = 0;
	while (*(out + i) && (*(out + i) != trunc))
		i++;
	*(out + i) = 0;
	return (out);
}
