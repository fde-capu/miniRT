/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:16:29 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 17:22:04 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	primitive_zzz_position(t_prm *cyl, t_ray *ray)
{
	t_vec	*zzz;
	t_mat	*rot;

	zzz = vector_scalar_multiply(cyl->o, -1.0);
	rot = vector_vector_rotation_matrix(g_z, cyl->n);
	primitive_translate(cyl, zzz);
	primitive_transform(cyl, rot);
	ray_translate(ray, zzz);
	ray_transform(ray, rot);
	vector_destroy(zzz);
	matrix_destroy(rot);
	return ;
}

void	primitive_translate(t_prm *prm, t_mat *trm)
{
	if (prm->o)
		prm->o = vectorx(prm->o, vector_translate(prm->o, trm));
	return ;
}

void	triangle_translate(t_tri *tri, t_mat *trm)
{
	if (tri->a)
		tri->a = vectorx(tri->a, vector_translate(tri->a, trm));
	if (tri->b)
		tri->b = vectorx(tri->b, vector_translate(tri->b, trm));
	if (tri->c)
		tri->c = vectorx(tri->c, vector_translate(tri->c, trm));
	if (tri->o)
		tri->o = vectorx(tri->o, vector_translate(tri->o, trm));
	return ;
}

void	triangle_transform(t_tri *tri, t_mat *trm)
{
	if (tri->a)
		vector_transform(&tri->a, trm);
	if (tri->b)
		vector_transform(&tri->b, trm);
	if (tri->c)
		vector_transform(&tri->c, trm);
	if (tri->n)
		vector_transform(&tri->n, trm);
	if (tri->o)
		vector_transform(&tri->o, trm);
	return ;
}

void	primitive_transform(t_prm *prm, t_mat *trm)
{
	if (prm->o)
		vector_transform(&prm->o, trm);
	if (prm->n)
		vector_transform(&prm->n, trm);
	return ;
}
