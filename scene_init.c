/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:40:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 17:04:08 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_amb_light	amb_light_init(double f, t_rgb rgb)
{
	t_amb_light	lit;

	lit.f = f;
	lit.rgb = rgb;
	return (lit);
}

t_cam		cam_init(t_d3d o, t_vec p, double fov)
{
	t_cam	cam;

	cam.o = o;
	cam.p = p;
	cam.fov = fov;
	return (cam);
}
