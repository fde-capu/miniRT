/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:37:52 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 13:43:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			scene_destroy(t_scn *sc)
{
	t_cam	*h;
	t_cam	*b;

	h = sc->cam_list;
	while (h)
	{
		b = h->nx;
		free(h);
		h = b;
	}

	t_light	*lh;
	t_light	*ln;
	lh = sc->lights;
	while (lh)
	{
		ln = ln->nx;
		free(lh);
		lh = ln;
	}

	t_sp *sph;
	t_sp *spn;
	sph = sc->spheres;
	while (sph)
	{
		spn = spn->nx;
		free(sph);
		sph = spn;
	}

	free (sc);
	return (1);
}
