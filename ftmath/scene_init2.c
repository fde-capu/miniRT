/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:17:15 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/21 18:30:08 by fde-capu         ###   ########.fr       */
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

void	intersect_phit(t_hit *hit)
{
	hit->phit = vector_scalar_multiply(hit->ray->d, hit->t);
	hit->phit = vectorx(hit->phit, vector_sum(hit->phit, hit->ray->o));
	DEBVEC("sp hit", hit->phit);
	return ;
}

void	intersect_normal(t_hit *hit)
{
	if (hit->primitive->type == TYPE_SP)
	{
		hit->n = vector_subtract(hit->phit, hit->primitive->o);
		vector_normalize(hit->n);
		DEBVEC("sp norm", hit->n);
	}
	return ;
}

void	intersect_complements(t_hit *hit)
{
	intersect_phit(hit);
	intersect_normal(hit);
	return ;
}

unsigned int	color_normal(t_vec *n)
{
	t_rgb	argb;
	t_vec	*tmp;

	tmp = vector_copy(n);
	tmp = vectorx(tmp, vector_scalar_sum(tmp, 1.0));
	tmp = vectorx(tmp, vector_scalar_multiply(tmp, 0.5));
	tmp = vectorx(tmp, vector_scalar_multiply(tmp, 255.0));
	argb = ft_rgb(0,
		vector_get_element(tmp, 1),
		vector_get_element(tmp, 2),
		vector_get_element(tmp, 3)
	);
	vector_destroy(tmp);
	return (ft_argbtoi(argb));
}
