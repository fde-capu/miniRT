/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whichar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:22:19 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 16:22:34 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Gets negative from `x` to point to char
** counting from the end of `char *`.
*/

#include "libft.h"

char	ft_whichar(const char *s, int x)
{
	char	*z;
	char	r;

	z = (char *)s;
	while (x < 0)
	{
		x += ft_strlen(z);
	}
	r = *(z + x);
	return (r);
}
