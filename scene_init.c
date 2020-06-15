/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:40:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 16:39:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		scene_init(t_scn *sc)
{
	g_scn = ft_calloc(sizeof(t_scn), 1);
	return ;
}

t_amb_light	amb_light_init(double f, t_rgb rgb)
{
	t_amb_light	lit;

	lit.f = f;
	lit.rgb = rgb;
	return (lit);
}

t_cam		*cam_init(t_d3d o, t_vec p, double fov)
{
	t_cam	*cam;

	cam = ft_calloc(sizeof(t_cam), 1);
	cam->o = o;
	cam->p = p;
	cam->fov = fov;
	cam->nx = g_scn->cam_list;
	g_scn->cam_list = cam;
	return (cam);
}

void		light_init(t_d3d o, double f, t_rgb rgb)
{
	t_light	*new;

	new = ft_calloc(sizeof(t_light), 1);
	new->o = o;
	new->f = f;
	new->rgb = rgb;
	new->nx = g_scn->lights;
	g_scn->lights = new;
}

void		sphere_init(t_d3d o, double d, t_rgb rgb)
{
	t_prim	*new;

	new = ft_calloc(sizeof(t_prim), 1);
	new->type = TYPE_SP;
	new->o = o;
	new->d = d;
	new->rgb = rgb;
	new->nx = g_scn->primitives;
	g_scn->primitives = new;
}

void		plane_init(t_d3d o, t_vec n, t_rgb rgb)
{
	t_prim	*new;

	new = ft_calloc(sizeof(t_prim), 1);
	new->type = TYPE_PL;
	new->o = o;
	new->n = n;
	new->rgb = rgb;
	new->nx = g_scn->primitives;
	g_scn->primitives = new;
	return ;
}
void		square_init(t_d3d o, t_vec n, double h, t_rgb rgb)
{
	t_prim	*new;

	new = ft_calloc(sizeof(t_prim), 1);
	new->type = TYPE_SQ;
	new->o = o;
	new->n = n;
	new->h = h;
	new->rgb = rgb;
	new->nx = g_scn->primitives;
	g_scn->primitives = new;
	return ;
}
void		cylinder_init(t_d3d o, t_vec n, double h, double d, t_rgb rgb)
{
	t_prim	*new;

	new = ft_calloc(sizeof(t_prim), 1);
	new->type = TYPE_CY;
	new->o = o;
	new->n = n;
	new->h = h;
	new->d = d;
	new->rgb = rgb;
	new->nx = g_scn->primitives;
	g_scn->primitives = new;
	return ;
}
void		triangle_init(t_d3d a, t_d3d b, t_d3d c, t_rgb rgb)
{
	t_tr	*new;

	new = ft_calloc(sizeof(t_tr), 1);
	new->a = a;
	new->b = b;
	new->c = c;
	new->n = ft_vector(0, 0, 0);
	new->rgb = rgb;
	new->nx = g_scn->faces;
	g_scn->faces= new;
	return ;
}
