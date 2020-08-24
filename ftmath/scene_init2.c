/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:17:15 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/24 16:33:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

t_prm		*sphere_init(t_vec *o, double d, t_rgb rgb)
{
	t_prm	*new;

	new = ft_calloc(sizeof(t_prm), 1);
	new->type = TYPE_SP;
	new->o = o;
	new->d = d;
	new->h = d / 2.0;
	new->rgb = rgb;
	return (new);
}

t_prm		*plane_init(t_vec *o, t_vec *n, t_rgb rgb)
{
	t_prm	*new;

	new = ft_calloc(sizeof(t_prm), 1);
	new->type = TYPE_PL;
	new->o = o;
	new->n = n;
	new->rgb = rgb;
	return (new);
}

t_prm		*square_init(t_vec *o, t_vec *n, double h, t_rgb rgb)
{
	t_prm	*new;

	new = ft_calloc(sizeof(t_prm), 1);
	new->type = TYPE_SQ;
	new->o = o;
	new->n = n;
	new->h = h;
	new->rgb = rgb;
	return (new);
}

t_prm		*cylinder_init(t_vec *o, t_vec *n, double h, double d)
{
	t_prm	*new;

	new = ft_calloc(sizeof(t_prm), 1);
	new->type = TYPE_CY;
	new->o = o;
	new->n = n;
	new->h = h;
	new->d = d;
	return (new);
}

void	intersect_destroy(t_hit *hit)
{
	if (!hit)
		return ;
	if (hit->phit)
		vector_destroy(hit->phit);
	if (hit->n)
		vector_destroy(hit->n);
	free(hit);
}

t_vec	*hit_point(t_ray *ray, double t)
{
	t_vec	*hitp;

	hitp = vector_scalar_multiply(ray->d, t);
	hitp = vectorx(hitp, vector_sum(hitp, ray->o));
	return (hitp);
}

void	intersect_phit(t_hit *hit)
{
	hit->phit = hit_point(hit->ray, hit->t);
	return ;
}

void	intersect_normal(t_hit *hit)
{
	if (hit->primitive->type == TYPE_SP)
	{
		hit->n = vector_subtract(hit->phit, hit->primitive->o);
		vector_normalize(hit->n);
	}
	else
		hit->n = vector_copy(hit->primitive->n);
//	if ((hit->primitive->type == TYPE_PL) || (hit->primitive->type == TYPE_SQ))
//	{
//		hit->n = vector_copy(hit->primitive->n);
//	}
	return ;
}

void	intersect_complements(t_hit *hit)
{
	intersect_phit(hit);
	intersect_normal(hit);
	return ;
}

t_rgb	color_normal(t_hit *hit)
{
	t_rgb	argb;
	t_vec	*tmp;

	tmp = vector_copy(hit->n);
	tmp = vectorx(tmp, vector_scalar_sum(tmp, 1.0));
	tmp = vectorx(tmp, vector_scalar_multiply(tmp, 0.5));
	tmp = vectorx(tmp, vector_scalar_multiply(tmp, 255.0));
	argb = ft_rgb(0,
		vector_get_element(tmp, 1),
		vector_get_element(tmp, 2),
		vector_get_element(tmp, 3)
	);
	vector_destroy(tmp);
	return (argb);
}

t_rgb	ft_argb_multiply(t_rgb argb, double factor)
{
	t_rgb	ret;

	ret = ft_rgb(
		argb.a * factor,
		argb.r * factor,
		argb.g * factor,
		argb.b * factor
	);
	return (ret);
}

t_rgb	ft_argb_sum(t_rgb a, t_rgb b)
{
	t_rgb	ret;

	ret = ft_rgb(
		a.a + b.a,
		a.r + b.r,
		a.g + b.g,
		a.b + b.b
	);
	return (ret);
}

t_rgb	color_distance(t_hit *hit)
{
	t_rgb			argb;
	double			v;

	v = ft_trig(hit->t, 255.0, 500.0);
	argb = ft_rgb(0, v, v, v);
	return (argb);
}

t_rgb	color_blend(t_rgb a, t_rgb b, double factor)
{
	a = ft_argb_multiply(a, factor);
	b = ft_argb_multiply(b, 1 - factor);
	return (ft_argb_sum(a, b));
}
