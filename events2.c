/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 02:04:40 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/30 02:13:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		translate_all_up(void *scn)
{
	translate_prm_tri_demo(scn, TRANSLATE_FACTOR);
	translate_lht_cam_demo(scn, TRANSLATE_FACTOR);
	render(g_mrt, 0);
	return (1);
}

int		translate_all_down(void *scn)
{
	translate_prm_tri_demo(scn, -TRANSLATE_FACTOR);
	translate_lht_cam_demo(scn, -TRANSLATE_FACTOR);
	render(g_mrt, 0);
	return (1);
}

t_mat	*demo_rotation(double factor)
{
	t_mat	*rot;

	rot = axis_angle_rotation(g_mrt->scn->cam_active->p, degtorad(factor));
	return (rot);
}

int		rotate_all_obj(void *scn)
{
	t_prm	*prm;
	t_scn	*s;
	t_mat	*trans;
	t_tri	*tri;

	s = (t_scn *)scn;
	prm = s->primitives;
	trans = demo_rotation(ROTATE_FACTOR);
	while (prm)
	{
		vector_transform(&prm->n, trans);
		prm = prm->nx;
	}
	tri = s->faces;
	while (tri)
	{
		triangle_rotate_in_place(tri, trans);
		tri = tri->nx;
	}
	matrix_destroy(trans);
	render(g_mrt, 0);
	return (1);
}

int		rotate_active_cam(void *scn)
{
	t_scn	*s;
	t_mat	*trans;
	t_cam	*cam;

	s = (t_scn *)scn;
	trans = demo_rotation(ROTATE_FACTOR);
	cam = s->cam_active;
	vector_transform(&cam->n, trans);
	vector_transform(&cam->p, trans);
	vector_transform(&cam->left, trans);
	matrix_destroy(trans);
	render(g_mrt, 0);
	return (1);
}
