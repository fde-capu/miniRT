/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 02:17:26 by fde-capu         ###   ########.fr       */
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

t_rgb			color_ambient(t_mrt *mrt)
{
	return (rgb_force(mrt->scn->ambient.rgb, mrt->scn->ambient.f));
}

t_rgb			color_diffuse(t_lht *light, t_hit *hit)
{
	t_rgb	dif;
	double	f;
	t_vec	*hit_to_light;
	double	intensity;

	dif = light->rgb;
	f = light->f;
	hit_to_light = vector_normal_construct(hit->phit, light->o);
	intensity = vector_dot_product(hit_to_light, hit->n) * DIFFUSE_REFLECTIVITY * f;
	intensity = intensity < 0.0 ? 0.0 : intensity;
	dif = rgb_force(dif, intensity);
	if (hit->primitive)
		dif = color_multiply(dif, hit->primitive->rgb);
	else
		dif = color_multiply(dif, hit->triangle->rgb);
	vector_destroy(hit_to_light);
	return (dif);
}

t_rgb			color_specular(t_lht *light, t_hit *hit)
{
	t_rgb	spec;
	double	f;
	t_vec	*reflection;
	double	intensity;
	t_mat	*rot;
	t_vec	*hit_to_light;

	f = light->f;
	hit_to_light = vector_normal_construct(hit->phit, light->o);
	spec = light->rgb;
	rot = vector_vector_rotation_matrix(hit->n, hit->ray->d);
	reflection = vector_copy(hit->n);
	vector_transform(&reflection, rot);
	intensity = vector_dot_product(reflection, hit_to_light) * -SPECULAR_INTENSITY;
	intensity = intensity < 0.0 ? 0.0 : intensity;
	intensity = ft_pow(intensity, SPECULAR_POWER);
	spec = rgb_force(spec, intensity);
	spec = rgb_force(spec, f);
	vector_destroy(reflection);
	matrix_destroy(rot);
	vector_destroy(hit_to_light);
	return (spec);
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

t_rgb			color_multiply(t_rgb ca, t_rgb cb)
{
	t_rgb	mult;
	int		a;
	int		r;
	int		g;
	int		b;

	a = (int)ca.a * (int)cb.a / 255;
	r = (int)ca.r * (int)cb.r / 255;
	g = (int)ca.g * (int)cb.g / 255;
	b = (int)ca.b * (int)cb.b / 255;
	mult.a = (unsigned char)a;
	mult.r = (unsigned char)r;
	mult.g = (unsigned char)g;
	mult.b = (unsigned char)b;
	return (mult);
}

unsigned int	color_trace(t_mrt *mrt, t_hit *hit)
{
	t_rgb	ambient;
	t_rgb	diffuse;
	t_rgb	specular;
	t_rgb	result;
	t_lht	*light;
	double	test;

	ambient = color_ambient(mrt);
	result = ambient;
	light = mrt->scn->lights;
	while (light)
	{
		test = can_see_light(mrt, hit, light->o);
		if (test)
		{
			diffuse = color_diffuse(light, hit);
			specular = color_specular(light, hit);
			result = color_add(result, diffuse);
			result = color_add(result, specular);
		}
		light = light->nx;
	}
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
