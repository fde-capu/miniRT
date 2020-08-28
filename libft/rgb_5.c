/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:29:50 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 17:59:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	skybox(int x, int y)
{
	return (((x * x) + (y * y) - 70) << 16);
}

t_rgb			color_ambient(t_mrt *mrt)
{
	return (rgb_force(mrt->scn->ambient.rgb, mrt->scn->ambient.f));
}

t_rgb			color_specular(t_lht *light, t_hit *hit)
{
	t_rgb	spec;
	t_vec	*reflection;
	double	intensity;
	t_mat	*rot;
	t_vec	*hit_to_light;

	hit_to_light = vector_normal_construct(hit->phit, light->o);
	spec = light->rgb;
	rot = vector_vector_rotation_matrix(hit->n, hit->ray->d);
	reflection = vector_copy(hit->n);
	vector_transform(&reflection, rot);
	intensity = vector_dot_product(reflection, hit_to_light) * \
		-SPECULAR_INTENSITY;
	intensity = intensity < 0.0 ? 0.0 : intensity;
	intensity = ft_pow(intensity, SPECULAR_POWER);
	spec = rgb_force(spec, intensity);
	spec = rgb_force(spec, light->f);
	vector_destroy(reflection);
	matrix_destroy(rot);
	vector_destroy(hit_to_light);
	return (spec);
}

t_rgb			color_diffuse(t_lht *light, t_hit *hit)
{
	t_rgb	diffuse;
	t_vec	*hit_to_light;
	double	intensity;

	diffuse = light->rgb;
	hit_to_light = vector_normal_construct(hit->phit, light->o);
	intensity = vector_dot_product(hit_to_light, hit->n) * \
		(DIFFUSE_REFLECTIVITY * light->f);
	intensity = intensity < 0.0 ? 0.0 : intensity;
	diffuse = rgb_force(diffuse, intensity);
	if (hit->primitive)
		diffuse = color_multiply(diffuse, hit->primitive->rgb);
	else
		diffuse = color_multiply(diffuse, hit->triangle->rgb);
	vector_destroy(hit_to_light);
	return (diffuse);
}
