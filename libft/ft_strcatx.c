/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 03:12:00 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/05 03:30:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcatx(char *dst, char *src)
{
	char	*x;

	x = ft_strcat(dst, src);
	if (src)
		free(src);
	if (dst)
		free(dst);
	return (x);
}
