/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:37:52 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/19 18:15:41 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

void		scn_free_list_lht(t_lht *lst)
{
	if (lst->nx)
		scn_free_list_lht(lst->nx);
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

void		scn_free_list_prm(t_prm *lst)
{
	if (lst->nx)
		scn_free_list_prm(lst->nx);
	free(lst);
	return ;
}

void		scn_free_list_tri(t_tri *lst)
{
	if (lst->nx)
		scn_free_list_tri(lst->nx);
	free(lst);
	return ;
}

int			scene_destroy(t_scn *sc)
{
	if (sc->cam_list)
		scn_free_list_cam(sc->cam_list);
	if (sc->lights)
		scn_free_list_lht(sc->lights);
	if (sc->primitives)
		scn_free_list_prm(sc->primitives);
	if (sc->faces)
		scn_free_list_tri(sc->faces);
	free(sc);
	return (1);
}
