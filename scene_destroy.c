/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:37:52 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 16:37:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		scn_free_list_light(t_light *lst)
{
	if (lst->nx)
		scn_free_list_light(lst->nx);
	free(lst);
	return ;
}

void		scn_free_list_cam(t_cam *lst)
{
	if (lst->nx)
		scn_free_list_cam(lst->nx);
	free(lst);
	return ;
}

void		scn_free_list_prim(t_prim *lst)
{
	if (lst->nx)
		scn_free_list_prim(lst->nx);
	free(lst);
	return ;
}

void		scn_free_list_tr(t_tr *lst)
{
	if (lst->nx)
		scn_free_list_tr(lst->nx);
	free(lst);
	return ;
}

int			scene_destroy(t_scn *sc)
{
	scn_free_list_cam(sc->cam_list);
	scn_free_list_light(sc->lights);
	scn_free_list_prim(sc->primitives);
	scn_free_list_tr(sc->faces);
	free (sc);
	return (1);
}
