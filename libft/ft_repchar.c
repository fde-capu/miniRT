/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:49:07 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 10:14:45 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns allocated *char of repeated char.
*/

char	*ft_repchar(char c, unsigned int rpt)
{
	char	*str;
	char	cc[2];

	cc[0] = c;
	cc[1] = 0;
	str = ft_strnew();
	while (rpt)
	{
		str = ft_xlloc(str, ft_strcat(str, cc));
		rpt--;
	}
	return (str);
}
