/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 20:00:14 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 18:04:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	cam = ft_calloc(sizeof(t_cam), 1);
	cam->fov = fov;
	cam->o = o;
	cam->p = p;
	missing_up_gambiarra(p, &cam->n, &cam->left);
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
	t_vec	*ta;
	t_vec	*tb;

	new = ft_calloc(sizeof(t_tri), 1);
	new->a = a;
	new->b = b;
	new->c = c;
	ta = vector_subtract(b, a);
	tb = vector_subtract(c, a);
	new->n = vector_cross_product(tb, ta);
	vector_normalize(new->n);
	vector_destroy(ta);
	vector_destroy(tb);
	new->rgb = rgb;
	new->o = triangle_center(new->a, new->b, new->c);
	return (new);
}
