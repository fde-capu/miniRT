/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:51:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 13:41:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	verbose_scene(void)
{
	DEBINT(MSG_RX, g_scn->resolution.x);
	DEBINT(MSG_RY, g_scn->resolution.y);
	DEBDBL("amb force", g_scn->ambient.f);
	DEBRGB("amb rgb", g_scn->ambient.rgb);
	DEBD3D("cam origin", g_scn->cam_active->o);
	DEBVEC("cam point", g_scn->cam_active->p);
	DEBDBL("cam fov", g_scn->cam_active->fov);
	DEBD3D("light origin", g_scn->lights->o);
	DEBDBL("light force", g_scn->lights->f);
	DEBRGB("light rgb", g_scn->lights->rgb);
	DEBD3D("sphere origin", g_scn->spheres->o);
	DEBDBL("sphere force", g_scn->spheres->d);
	DEBRGB("sphere rgb", g_scn->spheres->rgb);
	return ;
}
