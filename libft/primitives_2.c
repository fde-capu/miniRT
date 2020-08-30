/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 01:57:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/30 02:03:41 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*triangle_center(t_vec *a, t_vec *b, t_vec *c)
{
	t_vec	*center;

	center = vector_sum(a, b);
	center = vectorx(center, vector_sum(center, c));
	center = vectorx(center, vector_scalar_multiply(center, 1.0 / 3.0));
	return (center);
}

void	primitive_rotate_in_place(t_prm *prm, t_mat *rot)
{
	if ((prm->type == TYPE_CY)
	|| (prm->type == TYPE_PL))
		primitive_transform(prm, rot);
	debug_primitive(prm);
	return ;
}

void	triangle_rotate_in_place(t_tri *tri, t_mat *rot)
{
	t_vec	*o;

	o = vector_copy(tri->o);
	triangle_zzz_position(tri);
	triangle_transform(tri, rot);
	tri->o = vectorx(tri->o, o);
	tri->a = vectorx(tri->a, vector_translate(tri->a, o));
	tri->b = vectorx(tri->b, vector_translate(tri->b, o));
	tri->c = vectorx(tri->c, vector_translate(tri->c, o));
	return ;
}

void	primitive_scale(t_prm *prm, double factor)
{
	t_vec	*vec;

	if ((prm->type == TYPE_SP)
	|| (prm->type == TYPE_CY))
	{
		prm->d *= factor;
		prm->h *= factor;
	}
	if (prm->type == TYPE_CY)
	{
		vec = vector_scalar_multiply(prm->n, factor > 1.0 ? -factor : factor);
		primitive_translate(prm, vec);
		vector_destroy(vec);
	}
	return ;
}

void	triangle_scale(t_tri *tri, double factor)
{
	tri->a = vectorx(tri->a, vector_origin_scale(tri->a, tri->o, factor));
	tri->b = vectorx(tri->b, vector_origin_scale(tri->b, tri->o, factor));
	tri->c = vectorx(tri->c, vector_origin_scale(tri->c, tri->o, factor));
	return ;
}
