/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:40:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/19 19:35:57 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

t_scn	*scene_init(void)
{
	return (ft_calloc(sizeof(t_scn), 1));
}

t_alt	amb_light_init(double f, t_rgb rgb)
{
	t_alt	lit;

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
	return (cam);
}

t_lht		*light_init(t_d3d o, double f, t_rgb rgb)
{
	t_lht	*new;

	new = ft_calloc(sizeof(t_lht), 1);
	new->o = o;
	new->f = f;
	new->rgb = rgb;
	return (new);
}

t_tri		*triangle_init(t_d3d a, t_d3d b, t_d3d c, t_rgb rgb)
{
	t_tri	*new;

	new = ft_calloc(sizeof(t_tri), 1);
	new->a = a;
	new->b = b;
	new->c = c;
	new->n = ft_vector(0, 0, 0);
	new->rgb = rgb;
	return (new);
}
