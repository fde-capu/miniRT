/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:40:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 17:22:27 by fde-capu         ###   ########.fr       */
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
	g_scn->faces = new;
	return ;
}
