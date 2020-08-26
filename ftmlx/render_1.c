/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/26 17:06:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

/*
**      v v v d   rgb  d  d i     v v v
** cam	o p n fov
** lht	o     f   rgb
** prm  o   n     rgb  h  d type
** tri      n     rgb             a b c
*/

t_rgb			rgb_force(t_rgb rgb, double f)
{
	t_rgb	nrgb;

	nrgb = rgb;
	nrgb.a *= f;
	nrgb.r *= f;
	nrgb.g *= f;
	nrgb.b *= f;
	return (nrgb);
}

unsigned int	color_force(t_rgb rgb, double f)
{
	return (ft_argbtoi(rgb_force(rgb, f)));
}

unsigned int	skybox(int x, int y)
{
	return (((x * x) + (y * y) - 70) << 16);
}

t_rgb			color_ambient(t_mrt *mrt, t_hit *hit)
{
	t_rgb	color;
	t_rgb	amb;
	double	f;

	f = mrt->scn->ambient.f;
	color = hit->primitive->rgb;
	color = rgb_force(color, f);
	amb = rgb_force(mrt->scn->ambient.rgb, f);
	color = color_blend(color, amb, 0.5);
	return (color);
}

t_rgb			color_diffuse(t_mrt *mrt, t_hit *hit)
{
	t_rgb	dif;
	double	f;
	t_vec	*hit_to_ligth;
	double	intensity;

	dif = mrt->scn->lights->rgb;
		f = mrt->scn->lights->f;
	hit_to_ligth = vector_subtract(mrt->scn->lights->o, hit->phit);
	vector_normalize(hit_to_ligth);
	intensity = vector_dot_product(hit_to_ligth, hit->n) * DIFFUSE_REFLECTIVITY * f;
	intensity = intensity < 0.0 ? 0.0 : intensity;
	dif = rgb_force(dif, intensity);
	vector_destroy(hit_to_ligth);
	return (dif);
}

t_rgb			color_add(t_rgb ca, t_rgb cb)
{
	t_rgb	add;
	int		a;
	int		r;
	int		g;
	int		b;

	a = ca.a + cb.a;
	r = ca.r + cb.r;
	g = ca.g + cb.g;
	b = ca.b + cb.b;
	a = a > 255 ? 255 : a;
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	add.a = (unsigned char)a;
	add.r = (unsigned char)r;
	add.g = (unsigned char)g;
	add.b = (unsigned char)b;
	return (add);
}

unsigned int	color_trace(t_mrt *mrt, t_hit *hit)
{
	t_rgb	ambient;
	t_rgb	diffuse;
	t_rgb	result;

	ambient = color_ambient(mrt, hit);
	diffuse = color_diffuse(mrt, hit);
	result = color_add(ambient, diffuse);
	return (ft_argbtoi(result));
}

void	render(t_mrt *mrt, int saving)
{
	int				x;
	int				y;
	t_ray			*ray;
	t_hit			*hit;
	unsigned int	color;

	ft_putstr(MSG_RENDERING);
	y = 1;
	while (y <= mrt->i.height)
	{
		x = 1;
		while (x <= mrt->i.width)
		{
			ray = mrt_ray(mrt, x, y);
			hit = collision_pix(mrt, ray);
			if (hit && BONUS)
				color = ft_argbtoi(color_normal(hit));
			if (hit && !BONUS)
				color = color_trace(mrt, hit);
			if (!hit && !BONUS)
				color = color_force(mrt->scn->ambient.rgb, mrt->scn->ambient.f);
			if (!hit && BONUS)
				color = skybox(x, y);
			ft_pix(mrt, x, y, color);
			intersect_destroy(hit);
			ray_destroy(ray);
			x++;
		}
		y++;
		if (!saving)
			flip(mrt);
	}
	ft_putstr(MSG_DONE);
	return ;
}
