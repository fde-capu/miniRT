/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 08:10:14 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 08:42:07 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ptoa(void *p)
{
	char		*o;
	long long	add_val;

	add_val = (long long)&p;
	o = ft_dtob(add_val, 16);
	return (o);
}
