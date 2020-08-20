/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:43:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 18:16:18 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

t_ray	*mrt_ray(t_mrt *mrt, int x, int y)
{
	t_vec	*b;
	t_ray	*ray;

	b = vector_build(3,							\
		matrix_get_element(mrt->pjt[X], x, y),	\
		matrix_get_element(mrt->pjt[Y], x, y),	\
		matrix_get_element(mrt->pjt[Z], x, y));
	ray = ray_build(mrt->scn->cam_active->o, b);
	vector_destroy(b);
	return (ray);
}

int		collision_pix(t_mrt *mrt, int x, int y)
{
	t_prm	*primitive;
	t_ray	*ray;

	// for evey object (prm and tri)
	//		find intersections
	//		keep if closest
	ray = mrt_ray(mrt, x, y);
	primitive = mrt->scn->primitives;
	while (primitive)
	{
		if (hit_sphere(ray, primitive))
		{
			ray_destroy(ray);
			return (1);
		}
		primitive = primitive->nx;
	}
	ray_destroy(ray);
	return (0);
}

void	flip(t_mrt *mrt)
{
	mlx_put_image_to_window(mrt->mlx, mrt->win, mrt->img, 0, 0);
	return ;
}
