/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 20:00:10 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 20:00:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

t_prm		*cylinder_init(t_vec *o, t_vec *n, double d, double h)
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

t_prm		*disc_init(t_vec *o, t_vec *n, double d, t_rgb rgb)
{
	t_prm	*new;

	new = plane_init(o, n, rgb);
	new->type = TYPE_DS;
	new->h = d / 2.0;
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
