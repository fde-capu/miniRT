/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 09:19:37 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/29 09:57:07 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

void	scn_add(int objtype, void *obj, t_scn *sc)
{
	if (objtype == TYPE_CAM)
	{
		((t_cam *)obj)->nx = sc->cam_list;
		sc->cam_list = (t_cam *)obj;
		sc->cam_active = sc->cam_active ? sc->cam_active : sc->cam_list;
	}
	if (objtype == TYPE_LHT)
	{
		((t_lht *)obj)->nx = sc->lights;
		sc->lights = (t_lht *)obj;
	}
	if (objtype == TYPE_PRM)
	{
		((t_prm *)obj)->nx = sc->primitives;
		sc->primitives = (t_prm *)obj;
	}
	if (objtype == TYPE_TRI)
	{
		((t_tri *)obj)->nx = sc->faces;
		sc->faces = (t_tri *)obj;
	}
	return ;
}
