/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmath_verb2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:49:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/03 08:43:13 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	verb_cam(t_scn *scn)
{
	t_cam	*c;

	c = scn->cam_list;
	while (c)
	{
		DEBVEC("cam origin", c->o);
		DEBVEC("cam point", c->p);
		DEBDBL("cam fov", c->fov);
		c = c->nx;
	}
	return ;
}

void	verb_cam_active(t_scn *scn)
{
	DEB("Active cam:");
	DEBVEC("cam origin", scn->cam_active->o);
	DEBVEC("cam point", scn->cam_active->p);
	DEBDBL("cam fov", scn->cam_active->fov);
	return ;
}

char	*prim_tpnm(int type)
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
