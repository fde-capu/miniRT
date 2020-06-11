/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbezier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 15:21:14 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 12:34:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbezier.h"

t_d2d			linint(t_d2d a, t_d2d b, double t)
{
	t_d2d	p;

	p.x = (a.x + ((b.x - a.x) * t));
	p.y = (a.y + ((b.y - a.y) * t));
	return (p);
}

t_d2d			cubic_bez(t_cub_bez bez, double t)
{
	t_d2d	p[6];

	p[0] = linint(bez.a, bez.b, t);
	p[1] = linint(bez.b, bez.c, t);
	p[2] = linint(bez.c, bez.d, t);
	p[3] = linint(p[0], p[1], t);
	p[4] = linint(p[1], p[2], t);
	p[5] = linint(p[3], p[4], t);
	return (p[5]);
}

t_cub_bez		bez_init(t_d2d a, t_d2d b, t_d2d c, t_d2d d)
{
	t_cub_bez	f;

	f.a.x = a.x;
	f.a.y = a.y;
	f.b.x = b.x;
	f.b.y = b.y;
	f.c.x = c.x;
	f.c.y = c.y;
	f.d.x = d.x;
	f.d.y = d.y;
	return (f);
}
