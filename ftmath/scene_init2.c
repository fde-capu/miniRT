/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:17:15 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/21 12:12:22 by fde-capu         ###   ########.fr       */
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

void	intersect_destroy(t_isc *isc)
{
	free(isc);
}
