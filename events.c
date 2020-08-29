/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 09:34:41 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 17:20:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	change_cam_up(void *scn)
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

int	change_cam_down(void *scn)
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

void	primitive_scale(t_prm *prm, double factor)
{
	t_vec	*vec;

	if ((prm->type == TYPE_SP)
	|| (prm->type == TYPE_CY))
	{
		prm->d *= factor;
		prm->h *= factor;
	}
	if (prm->type == TYPE_CY)
	{
		vec = vector_scalar_multiply(prm->n, factor > 1.0 ? -factor : factor);
		primitive_translate(prm, vec);
		vector_destroy(vec);
	}
	return ;
}

t_vec	*triangle_center(t_vec *a, t_vec *b, t_vec *c)
{
	t_vec	*center;

	DEB("oops no center");
	center = vector_empty(3);
	vector_put_element(center, 1, (vector_get_element(a, 1) + vector_get_element(a, 2) + vector_get_element(a, 3) / 3.0));
	vector_put_element(center, 2, (vector_get_element(b, 1) + vector_get_element(b, 2) + vector_get_element(b, 3) / 3.0));
	vector_put_element(center, 3, (vector_get_element(c, 1) + vector_get_element(c, 2) + vector_get_element(c, 3) / 3.0));
	return (center);
}

void	triangle_scale(t_tri *tri, double factor)
{
	if (!tri->o)
		tri->o = triangle_center(tri->a, tri->b, tri->c);
	tri->a = vectorx(tri->a, vector_origin_scale(tri->a, tri->o, factor));
	tri->b = vectorx(tri->b, vector_origin_scale(tri->b, tri->o, factor));
	tri->c = vectorx(tri->c, vector_origin_scale(tri->c, tri->o, factor));
	return ;
}

int	scale_up(void *scn)
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

int	scale_down(void *scn)
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
