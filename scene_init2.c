/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:17:15 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 17:27:21 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		sphere_init(t_d3d o, double d, t_rgb rgb)
{
	t_prim	*new;

	new = ft_calloc(sizeof(t_prim), 1);
	new->type = TYPE_SP;
	new->o = o;
	new->d = d;
	new->rgb = rgb;
	new->nx = g_scn->primitives;
	g_scn->primitives = new;
}

void		plane_init(t_d3d o, t_vec n, t_rgb rgb)
{
	t_prim	*new;

	new = ft_calloc(sizeof(t_prim), 1);
	new->type = TYPE_PL;
	new->o = o;
	new->n = n;
	new->rgb = rgb;
	new->nx = g_scn->primitives;
	g_scn->primitives = new;
	return ;
}

void		square_init(t_d3d o, t_vec n, double h, t_rgb rgb)
{
	t_prim	*new;

	new = ft_calloc(sizeof(t_prim), 1);
	new->type = TYPE_SQ;
	new->o = o;
	new->n = n;
	new->h = h;
	new->rgb = rgb;
	new->nx = g_scn->primitives;
	g_scn->primitives = new;
	return ;
}

void		cylinder_init(t_d3d o, t_vec n, double h, double d)
{
	t_prim	*new;

	new = ft_calloc(sizeof(t_prim), 1);
	new->type = TYPE_CY;
	new->o = o;
	new->n = n;
	new->h = h;
	new->d = d;
	new->nx = g_scn->primitives;
	g_scn->primitives = new;
	return ;
}
