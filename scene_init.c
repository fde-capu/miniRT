/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:40:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 12:36:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		scene_init(t_scn *sc)
{
	g_scn = ft_calloc(sizeof(t_scn), 1);
	return ;
}

int			scene_destroy(t_scn *sc)
{
	t_cam	*h;
	t_cam	*b;

	h = sc->cam_list;
	while (h)
	{
		b = h->nx;
		free(h);
		h = b;
	}
	free (sc);
	return (1);
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
