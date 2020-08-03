/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:14:43 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/03 16:14:53 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_vtoa(t_vec *vec)
{
	char	*o;
	t_dbl	*h;

	o = ft_strnew();
	h = vec->i;
	while (h)
	{
		o = ft_strcatx(o, ft_dtoa(h->d));
		h = h->nx;
		if (h)
			o = ft_strcatxl(o, ",");
	}
	return (o);
}
