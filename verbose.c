/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:51:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/11 14:01:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	verbose_scene(void)
{
	DEBINT(MSG_RX, g_scn.r.x);
	DEBINT(MSG_RY, g_scn.r.y);
	DEBDBL("amb force", g_scn.a.f);
	DEBRGB("amb rgb", g_scn.a.rgb);
	DEBD3D("cam origin", g_scn.c.o);
	DEBVEC("cam point", g_scn.c.p);
	DEBDBL("cam fov", g_scn.c.fov);
	return ;
}
