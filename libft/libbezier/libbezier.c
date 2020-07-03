/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbezier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 15:21:14 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/02 14:28:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbezier.h"

t_vec			*linint(t_vec *a, t_vec *b, double t)
{
	t_vec	*p;

	p = ft_vec(2, (ft_v(a, 1) + ((ft_v(b, 1) - ft_v(a, 1)) * t)),
		(ft_v(a, 2) + ((ft_v(b, 2) - ft_v(a, 2)) * t)));
	return (p);
}

t_vec			*cubic_bez(t_cub_bez bez, double t)
{
	t_vec	*p[6];

	p[0] = linint(bez.a, bez.b, t);
	p[1] = linint(bez.b, bez.c, t);
	p[2] = linint(bez.c, bez.d, t);
	p[3] = linint(p[0], p[1], t);
	p[4] = linint(p[1], p[2], t);
	p[5] = linint(p[3], p[4], t);
	return (p[5]);
}

t_cub_bez		bez_init(t_vec *a, t_vec *b, t_vec *c, t_vec *d)
{
	t_cub_bez	f;

	f.a = a;
	f.b = b;
	f.c = c;
	f.d = d;
	return (f);
}
