/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:23:42 by fde-capu          #+#    #+#             */
/*   Updated: 2020/09/03 00:28:07 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	ambient = color_ambient(mrt);
	result = ambient;
	light = mrt->scn->lights;
	while (light)
	{
		if (can_see_light(mrt, hit, light->o))
		{
			diffuse = color_diffuse(light, hit);
			specular = color_specular(light, hit);
			result = color_add(result, diffuse);
			result = color_add(result, specular);
			result = light_decay(light, hit, result);
		}
		light = light->nx;
	}
	return (ft_argbtoi(result));
}

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
