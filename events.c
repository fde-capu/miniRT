/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 09:34:41 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/30 02:06:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		change_cam_up(void *scn)
{
	t_scn	*s;
	t_cam	*nnx;

	s = ((t_scn *)scn);
	nnx = &*s->cam_active;
	while ((s->cam_active->nx ? s->cam_active->nx : s->cam_list) != nnx)
		s->cam_active = s->cam_active->nx ? s->cam_active->nx : s->cam_list;
	verb_cam_active((t_scn *)scn);
	render(g_mrt, 0);
	return (1);
}

int		change_cam_down(void *scn)
{
	t_cam	*cam;
	t_scn	*s;

	s = (t_scn *)scn;
	cam = s->cam_active;
	s->cam_active = s->cam_active->nx ? s->cam_active->nx : s->cam_list;
	verb_cam_active((t_scn *)scn);
	render(g_mrt, 0);
	return (1);
}

int		scale_up(void *scn)
{
	t_prm	*prm;
	t_scn	*s;
	t_tri	*tri;

	s = (t_scn *)scn;
	prm = s->primitives;
	while (prm)
	{
		primitive_scale(prm, SCALE_FACTOR);
		prm = prm->nx;
	}
	tri = s->faces;
	while (tri)
	{
		triangle_scale(tri, SCALE_FACTOR);
		tri = tri->nx;
	}
	render(g_mrt, 0);
	return (1);
}

int		scale_down(void *scn)
{
	t_prm	*prm;
	t_scn	*s;
	t_tri	*tri;

	s = (t_scn *)scn;
	prm = s->primitives;
	while (prm)
	{
		primitive_scale(prm, 1.0 / SCALE_FACTOR);
		prm = prm->nx;
	}
	tri = s->faces;
	while (tri)
	{
		triangle_scale(tri, 1.0 / SCALE_FACTOR);
		tri = tri->nx;
	}
	render(g_mrt, 0);
	return (1);
}

t_vec	*demo_trans(t_vec *o, double factor)
{
	t_vec	*demo;

	demo = vector_copy(o);
	vector_normalize(demo);
	demo = vectorx(demo, vector_scalar_multiply(demo, factor));
	return (demo);
}
