/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:17:31 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 00:58:42 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ray	*ray_quadratic_gambiarra(t_ray *ray3d, double *a, double *b, double *c)
{
	double	d[2];
	double	z[2];
	t_ray	*ray;

	ray = ray_copy(ray3d);
	d[X] = vector_get_element(ray->d, 1);
	d[Y] = vector_get_element(ray->d, 2);
	z[X] = vector_get_element(ray->a, 1);
	z[Y] = vector_get_element(ray->a, 2);
	*c = ((z[X] * z[X]) + (z[Y] * z[Y])) - ((*a / 2) * (*a / 2));
	*a = ((d[X] * d[X]) + (d[Y] * d[Y]));
	*b = ((z[X] * d[X]) + (z[Y] * d[Y])) * 2;
	return (ray);
}

void	ray_smash_z(t_ray *ray)
{
	vector_put_element(ray->a, 3, 0.0);
	vector_put_element(ray->b, 3, 0.0);
	vector_put_element(ray->d, 3, 0.0);
	vector_normalize(ray->d);
	return ;
}

void	ray_destroy(t_ray *ray)
{
	vector_destroy(ray->a);
	vector_destroy(ray->b);
	vector_destroy(ray->d);
	return (free(ray));
}

void	ray_verb(char *str, t_ray *ray)
{
	DEB(str);
	DEBVEC("a", ray->a);
	DEBVEC("b", ray->b);
	DEBVEC("d", ray->d);
	return ;
}

double	ray_destroy_and_return(t_ray *ray, double val)
{
	ray_destroy(ray);
	return (val);
}
