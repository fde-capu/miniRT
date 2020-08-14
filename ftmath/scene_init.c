/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:40:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/14 16:20:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

t_scn	*scene_init(void)
{
	t_scn	*scn;

	scn = ft_calloc(sizeof(t_scn), 1);
	g_x = vector_build(3, 1.0, 0.0, 0.0);
	g_y = vector_build(3, 0.0, 1.0, 0.0);
	g_z = vector_build(3, 0.0, 0.0, 1.0);
	return (scn);
}

t_alt	amb_light_init(double f, t_rgb rgb)
{
	t_alt	lit;

	lit.f = f;
	lit.rgb = rgb;
	return (lit);
}

t_cam	*cam_init(t_vec *o, t_vec *p, double fov)
{
	t_cam	*cam;
	t_mat	*rvv;

	cam = ft_calloc(sizeof(t_cam), 1);
	cam->fov = fov;
	cam->o = o;
	cam->p = vector_scalar_multiply(g_z, -1.0);
	cam->n = vector_copy(g_y);
	cam->side = vector_scalar_multiply(g_x, -1.0);
	rvv = rotvv(cam->p, p);
	vector_destroy(p);
	vector_transform(&cam->p, rvv);
	vector_transform(&cam->n, rvv);
	vector_transform(&cam->side, rvv);
	matrix_destroy(rvv);
	return (cam);
}

t_lht	*light_init(t_vec *o, double f, t_rgb rgb)
{
	t_lht	*new;

	new = ft_calloc(sizeof(t_lht), 1);
	new->o = o;
	new->f = f;
	new->rgb = rgb;
	return (new);
}

t_tri	*triangle_init(t_vec *a, t_vec *b, t_vec *c, t_rgb rgb)
{
	t_tri	*new;

	new = ft_calloc(sizeof(t_tri), 1);
	new->a = a;
	new->b = b;
	new->c = c;
	new->n = vector_build(3, 0.0, 0.0, 0.0);
	new->rgb = rgb;
	return (new);
}
