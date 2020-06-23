/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 09:34:41 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/23 15:19:42 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	change_cam(void *scn)
{
	t_cam	*cam;
	t_scn	*s;

	s = (t_scn *)scn;
	cam = s->cam_active;
	s->cam_active = s->cam_active->nx ?: s->cam_list;
	DEB("Changed cam.");
	verb_cam_active(s);
	return (0);
}
