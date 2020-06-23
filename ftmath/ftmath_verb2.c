/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmath_verb2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:49:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/23 14:53:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

void	verb_cam(t_scn *scn)
{
	t_cam	*c;

	c = scn->cam_list;
	while (c)
	{
		DEBD3D("cam origin", c->o);
		DEBVEC("cam point", c->p);
		DEBDBL("cam fov", c->fov);
		c = c->nx;
	}
	return ;
}

void	verb_cam_active(t_scn *scn)
{
	DEB("Active cam:");
	DEBD3D("cam origin", scn->cam_active->o);
	DEBVEC("cam point", scn->cam_active->p);
	DEBDBL("cam fov", scn->cam_active->fov);
	return ;
}
