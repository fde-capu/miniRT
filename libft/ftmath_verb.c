/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmath_verb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:51:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/03 08:39:28 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	verb_lights(t_scn *scn)
{
	t_lht	*h;

	h = scn->lights;
	while (h)
	{
		DEBVEC("light origin", h->o);
		DEBDBL("light force", h->f);
		DEBRGB("light argb", h->rgb);
		h = h->nx;
	}
	return ;
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
		DEBVEC("origin", h->o);
		DEBVEC("normal", h->n);
		DEBDBL("height", h->h);
		DEBDBL("diameter", h->d);
		DEBRGB("ARGB", h->rgb);
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
		DEBVEC("face a", h->a);
		DEBVEC("face b", h->b);
		DEBVEC("face c", h->c);
		DEBRGB("face argb", h->rgb);
		h = h->nx;
	}
	return ;
}

void	verbose_scene(t_scn *scn)
{
	DEBVEC("resolution", scn->resolution);
	DEBDBL("amb force", scn->ambient.f);
	DEBRGB("amb argb", scn->ambient.rgb);
	verb_cam(scn);
	verb_cam_active(scn);
	verb_lights(scn);
	verb_primitives(scn);
	verb_faces(scn);
	return ;
}
