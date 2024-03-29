/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:17:31 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 03:56:00 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	quadratic_build(t_ray *ray, double *a, double *b, double *c)
{
	double	d[2];
	double	z[2];

	d[X] = vector_get_element(ray->d, 1);
	d[Y] = vector_get_element(ray->d, 2);
	z[X] = vector_get_element(ray->a, 1);
	z[Y] = vector_get_element(ray->a, 2);
	*c = ((z[X] * z[X]) + (z[Y] * z[Y])) - ((*a / 2) * (*a / 2));
	*a = ((d[X] * d[X]) + (d[Y] * d[Y]));
	*b = ((z[X] * d[X]) + (z[Y] * d[Y])) * 2;
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
