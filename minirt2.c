/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 09:34:41 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/24 12:28:58 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	change_cam_up(void *scn)
{
	t_scn	*s;
	t_cam	*nnx;

	DEB("noshift");
	s = ((t_scn *)scn);
	nnx = &*s->cam_active;
	while ((s->cam_active->nx ? s->cam_active->nx : s->cam_list) != nnx)
		s->cam_active = s->cam_active->nx ? s->cam_active->nx : s->cam_list;
	verb_cam_active((t_scn *)scn);
	return (1);
}

int	change_cam_down(void *scn)
{
	t_cam	*cam;
	t_scn	*s;

	s = (t_scn *)scn;
	cam = s->cam_active;
	s->cam_active = s->cam_active->nx ? s->cam_active->nx : s->cam_list;
	verb_cam_active((t_scn *)scn);
	return (1);
}
