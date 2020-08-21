/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:43:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/21 12:11:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

t_ray	*mrt_ray(t_mrt *mrt, int x, int y)
{
	t_vec	*b;
	t_ray	*ray;

	b = pjt_pixtocam(mrt, x, y);
	ray = ray_build(mrt->scn->cam_active->o, b);
	vector_destroy(b);
	return (ray);
}

t_isc	*collision_pix(t_mrt *mrt, t_ray *ray)
{
	t_prm	*primitive;
	double	test;
	t_isc	*intersection;

	// for evey object (prm and tri)
	//		find intersections
	//		keep if closest
	intersection = ft_calloc(sizeof(t_isc), 1);
	intersection->t = MAX_DEPTH;
	primitive = mrt->scn->primitives;
	while (primitive)
	{
		test = hit_sphere(ray, primitive);
		if (test > 0.0)
		{
			if (test < intersection->t)
			{
				intersection->t = test;
				intersection->primitive = primitive;
				intersection->ray = ray;
			}
		}
		primitive = primitive->nx;
	}
	if (intersection->t != MAX_DEPTH)
	{
		return (intersection);
	}
	intersect_destroy(intersection);
	return (0);
}

void	flip(t_mrt *mrt)
{
	mlx_put_image_to_window(mrt->mlx, mrt->win, mrt->img, 0, 0);
	return ;
}
