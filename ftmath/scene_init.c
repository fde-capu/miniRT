/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:40:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/10 13:07:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

t_scn	*scene_init(void)
{
	t_scn	*scn;

	scn = ft_calloc(sizeof(t_scn), 1);
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
	t_vec	*tilt;

	cam = ft_calloc(sizeof(t_cam), 1);
	cam->o = o;
	cam->p = p;
	tilt = vector_build(3, (double)0, (double)1, (double)0);
	if (vector_equal(tilt, cam->p))
		cam->n = vector_build(3, (double)0, (double)0, (double)1);
	else
		cam->n = vector_cross_product(p, tilt);
	vector_destroy(tilt);
	cam->fov = fov;
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
	new->n = vector_build(3, (double)0, (double)0, (double)0);
	new->rgb = rgb;
	return (new);
}
