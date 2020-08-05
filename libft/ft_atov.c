/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:13:48 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/03 16:27:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*ft_atov(char *str)
{
	t_vec	*vec;
	char	*h;
	char	*s;
	double	d;
	int		n;

	h = str;
	s = str;
	n = 0;
	vec = vector_new();
	while ((*h) && (h = ft_check(h, REG_DOUBLE)))
	{
		d = ft_atod(s);
		vec->i = lstdbl_addlast(vec->i, d);
		h += *h == ',' ? 1 : 0;
		s = h;
		n++;
	}
	vec->m = n;
	return (vec);
}
