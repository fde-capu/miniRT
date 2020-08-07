/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmath_verb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:51:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/07 15:16:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	verb_lights(t_scn *scn)
{
	t_lht	*h;

	h = scn->lights;
	while (h)
	{
		DEB(TIT_LHT);
		DEBVEC(S_ORIGIN, h->o);
		DEBDBL(S_FORCE, h->f);
		DEBRGB(S_COLOR, h->rgb);
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
		DEB(TIT_PRM);
		DEBSTR(S_TYPE, t = primitive_type_number(h->type));
		DEBVEC(S_ORIGIN, h->o);
		if (!ft_stridentical(t, TYPE_SP_NM))
			DEBVEC(S_NORMAL, h->n);
		free(t);
		DEBDBL(S_HEIGHT, h->h);
		DEBDBL(S_WIDTH, h->d);
		DEBRGB(S_COLOR, h->rgb);
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
		DEB(TIT_TRI);
		DEBVEC(S_VERTEX, h->a);
		DEBVEC(S_VERTEX, h->b);
		DEBVEC(S_VERTEX, h->c);
		DEBRGB(S_COLOR, h->rgb);
		h = h->nx;
	}
	return ;
}

void	verbose_scene(t_scn *scn)
{
	DEB(TIT_SCN);
	DEBVEC(S_RESOLUTION, scn->resolution);
	DEBDBL(S_FORCE, scn->ambient.f);
	DEBRGB(S_COLOR, scn->ambient.rgb);
	verb_cam(scn);
	verb_cam_active(scn);
	verb_lights(scn);
	verb_primitives(scn);
	verb_faces(scn);
	return ;
}
