/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmath_verb2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:49:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 08:33:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	verb_cam(t_scn *scn)
{
	t_cam	*c;

	c = scn->cam_list;
	while (c)
	{
		DEB(TIT_CAM);
		DEBVEC(S_ORIGIN, c->o);
		DEBVEC(S_NORMAL, c->p);
		DEBDBL(S_FOV, c->fov);
		c = c->nx;
	}
	return ;
}

void	verb_cam_active(t_scn *scn)
{
	DEB(TIT_CAM_ACT);
	DEBVEC(S_ORIGIN, scn->cam_active->o);
	DEBVEC(S_NORMAL, scn->cam_active->p);
	DEBDBL(S_FOV, scn->cam_active->fov);
	return ;
}

char	*prim_type_number(int type)
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
