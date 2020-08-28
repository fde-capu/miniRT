/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_rt_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 23:16:47 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/28 05:08:00 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scn_make_cylinder(t_scn *sc, char **c)
{
	t_vec	*origin_b;
	t_vec	*normal;
	double	diameter;
	double	height;
	t_vec	*origin_t;

	origin_b = ft_atov(c[1]);
	normal = ft_atov(c[2]);
	diameter = ft_atod(c[3]);
	height = ft_atod(c[4]);
	scn_add(TYPE_PRM, cylinder_init(origin_b, normal, diameter, height), sc);
	sc->primitives->rgb = ft_atorgb(c[5]);
	if (BONUS)
	{
		origin_t = vector_scalar_multiply(normal, height);
		origin_t = vectorx(origin_t, vector_sum(origin_t, origin_b));
		scn_add(TYPE_PRM, disc_init(origin_t, vector_copy(normal), \
			diameter, ft_atorgb(c[5])), sc);
		normal = vector_scalar_multiply(normal, -1.0);
		scn_add(TYPE_PRM, disc_init(vector_copy(origin_b), normal, \
			diameter, ft_atorgb(c[5])), sc);
	}
	return ;
}

void	scn_make_square(t_scn *sc, char **c)
{
	t_prm	*square;
	t_vec	*p[4];
	t_mat	*rot;
	t_tri	*tri[2];

	square = square_init(ft_atov(c[1]), ft_atov(c[2]), ft_atod(c[3]), \
		ft_atorgb(c[4]));
	scn_add(TYPE_PRM, square, sc);
	p[0] = vector_build(3, -square->h / 2.0, square->h / 2.0, 0.0);
	p[1] = vector_build(3, square->h / 2.0, square->h / 2.0, 0.0);
	p[2] = vector_build(3, square->h / 2.0, -square->h / 2.0, 0.0);
	p[3] = vector_build(3, -square->h / 2.0, -square->h / 2.0, 0.0);
	tri[0] = triangle_init(p[0], p[1], p[2], square->rgb);
	tri[1] = triangle_init(vector_copy(p[2]), p[3], vector_copy(p[0]), \
		square->rgb);
	rot = vector_vector_rotation_matrix(g_z, square->n);
	triangle_transform(tri[0], rot);
	triangle_transform(tri[1], rot);
	triangle_translate(tri[0], square->o);
	triangle_translate(tri[1], square->o);
	scn_add(TYPE_TRI, tri[0], sc);
	scn_add(TYPE_TRI, tri[1], sc);
	matrix_destroy(rot);
	return ;
}
