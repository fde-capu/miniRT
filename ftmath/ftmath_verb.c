/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_verb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:51:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/19 18:07:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

void	verb_lights(t_scn *scn)
{
	t_lht	*h;

	h = scn->lights;
	while (h)
	{
		DEBD3D("light origin", h->o);
		DEBDBL("light force", h->f);
		DEBRGB("light rgb", h->rgb);
		h = h->nx;
	}
	return ;
}

char	*prim_tpnm(int type)
{
	if (type == TYPE_SP)
		return (ft_str(TYPE_SP_NM));
	if (type == TYPE_PL)
		return (ft_str(TYPE_PL_NM));
	if (type == TYPE_SQ)
		return (ft_str(TYPE_SQ_NM));
	if (type == TYPE_CY)
		return (ft_str(TYPE_CY_NM));
	return (0);
}

void	verb_primitives(t_scn *scn)
{
	t_prm	*h;
	char	*t;

	h = scn->primitives;
	while (h)
	{
		DEBSTR("Type", t = prim_tpnm(h->type));
		free(t);
		DEBD3D("origin", h->o);
		DEBVEC("normal", h->n);
		DEBDBL("height", h->h);
		DEBDBL("diameter", h->d);
		DEBRGB("RGB", h->rgb);
		h = h->nx;
	}
	return ;
}

void	verb_faces(t_scn *scn)
{
	t_tri	*h;

	h = scn->faces;
	while (h)
	{
		DEBD3D("face a", h->a);
		DEBD3D("face b", h->b);
		DEBD3D("face c", h->c);
		DEBRGB("face rgb", h->rgb);
		h = h->nx;
	}
	return ;
}

void	verbose_scene(t_scn *scn)
{
	DEBINT2("resolution", scn->resolution.x, scn->resolution.y);
	DEBDBL("amb force", scn->ambient.f);
	DEBRGB("amb rgb", scn->ambient.rgb);
	DEBD3D("cam origin", scn->cam_active->o);
	DEBVEC("cam point", scn->cam_active->p);
	DEBDBL("cam fov", scn->cam_active->fov);
	verb_lights(scn);
	verb_primitives(scn);
	verb_faces(scn);
	return ;
}
