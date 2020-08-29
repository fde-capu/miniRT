/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:17:26 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 14:04:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ray	*ray_build(t_vec *a, t_vec *point_b)
{
	t_ray	*ray;

	ray = ft_calloc(sizeof(t_ray), 1);
	ray->a = vector_copy(a);
	ray->b = vector_copy(point_b);
	ray->d = vector_subtract(point_b, a);
	vector_normalize(ray->d);
	return (ray);
}

t_ray	*ray_copy(t_ray *src)
{
	t_ray	*ray;

	ray = ft_calloc(sizeof(t_ray), 1);
	ray->a = vector_copy(src->a);
	ray->b = vector_copy(src->b);
	ray->d = vector_copy(src->d);
	return (ray);
}

void	ray_transform(t_ray *ray, t_mat *trn)
{
	vector_transform(&(ray->a), trn);
	vector_transform(&(ray->b), trn);
	vector_transform(&(ray->d), trn);
	return ;
}

void	ray_translate(t_ray *ray, t_vec *trn)
{
	ray->a = vectorx(ray->a, vector_translate(ray->a, trn));
	ray->b = vectorx(ray->b, vector_translate(ray->b, trn));
	return ;
}

void	vector_smash_z(t_vec *vec)
{
	vector_put_element(vec, 3, 0.0);
	return ;
}
