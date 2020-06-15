/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:51:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 17:28:26 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	verb_lights(void)
{
	t_light	*h;

	h = g_scn->lights;
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

void	verb_primitives(void)
{
	t_prim	*h;
	char	*t;

	h = g_scn->primitives;
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

void	verb_faces(void)
{
	t_tr	*h;

	h = g_scn->faces;
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

void	verbose_scene(void)
{
	DEBINT(MSG_RX, g_scn->resolution.x);
	DEBINT(MSG_RY, g_scn->resolution.y);
	DEBDBL("amb force", g_scn->ambient.f);
	DEBRGB("amb rgb", g_scn->ambient.rgb);
	DEBD3D("cam origin", g_scn->cam_active->o);
	DEBVEC("cam point", g_scn->cam_active->p);
	DEBDBL("cam fov", g_scn->cam_active->fov);
	verb_lights();
	verb_primitives();
	verb_faces();
	return ;
}
