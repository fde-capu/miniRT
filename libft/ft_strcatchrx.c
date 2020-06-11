/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatchrx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 13:23:00 by fde-capu          #+#    #+#             */
/*   Updated: 2020/04/23 13:23:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcatchrx(char *dst, char *c)
{
	char	*x;

	x = ft_strdup(c);
	x[1] = 0;
	dst = ft_strcatx(dst, x);
	return (dst);
}
