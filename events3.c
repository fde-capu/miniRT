/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 02:08:06 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/30 02:34:31 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		translate_prm_tri_demo(void *scn, double factor)
{
	t_prm	*prm;
	t_tri	*tri;
	t_scn	*s;
	t_vec	*trans;

	s = (t_scn *)scn;
	prm = s->primitives;
	trans = vector_new();
	while (prm)
	{
		trans = vectorx(trans, demo_trans(prm->o, factor));
		primitive_translate(prm, trans);
		prm = prm->nx;
	}
	tri = s->faces;
	while (tri)
	{
		trans = vectorx(trans, demo_trans(tri->o, factor));
		triangle_translate(tri, trans);
		tri = tri->nx;
	}
	vector_destroy(trans);
	return (1);
}

int		translate_lht_cam_demo(void *scn, double factor)
{
	t_scn	*s;
	t_vec	*trans;
	t_lht	*lht;
	t_cam	*cam;

	s = (t_scn *)scn;
	trans = vector_new();
	lht = s->lights;
	while (lht)
	{
		trans = vectorx(trans, demo_trans(lht->o, factor));
		lht->o = vectorx(lht->o, vector_translate(lht->o, trans));
		lht = lht->nx;
	}
	cam = s->cam_list;
	while (cam)
	{
		trans = vectorx(trans, demo_trans(cam->o, factor));
		cam->o = vectorx(cam->o, vector_translate(cam->o, trans));
		cam = cam->nx;
	}
	vector_destroy(trans);
	return (1);
}
