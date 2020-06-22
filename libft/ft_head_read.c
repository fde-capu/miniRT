/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:15:05 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/22 14:35:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_head_read(char **h, char *r, char *key)
{
	if (ft_strbegins(r, key))
	{
		*h += ft_strlen(key);
		return (1);
	}
	return (0);
}
