/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:17:31 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 17:35:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
