/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:46:48 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 10:50:04 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees arg1, returns arg2.
*/

void	*ft_xlloc(void *arg1, void *arg2)
{
	if (arg1)
		free(arg1);
	return (arg2);
}

void	*ft_x(void *a1, void *a2)
{
	return (ft_xlloc(a1, a2));
}
