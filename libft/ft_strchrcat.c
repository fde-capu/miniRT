/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:01:04 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/11 15:30:09 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns allocated concatenation of `dst` with figure `src`.
*/

char	*ft_strchrcat(const char *dst, const char src)
{
	char	nc[2];

	nc[0] = src;
	nc[1] = 0;
	return (ft_strcat(dst, nc));
}
