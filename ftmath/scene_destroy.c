/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:37:52 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/10 17:12:51 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

void		scn_free_list_lht(t_lht *lst)
{
	if (lst->nx)
		scn_free_list_lht(lst->nx);
	vector_destroy(lst->o);
	free(lst);
	return ;
}

void		scn_free_list_cam(t_cam *lst)
{
	if (lst->nx)
		scn_free_list_cam(lst->nx);
	vector_destroy(lst->o);
	vector_destroy(lst->p);
	vector_destroy(lst->n);
	free(lst);
	return ;
}

void		scn_free_list_prm(t_prm *lst)
{
	if (lst->nx)
		scn_free_list_prm(lst->nx);
	vector_destroy(lst->o);
	vector_destroy(lst->n);
	free(lst);
	return ;
}

void		scn_free_list_tri(t_tri *lst)
{
	if (lst->nx)
		scn_free_list_tri(lst->nx);
	vector_destroy(lst->a);
	vector_destroy(lst->b);
	vector_destroy(lst->c);
	vector_destroy(lst->n);
	free(lst);
	return ;
}

int			scene_destroy(t_scn *sc)
{
	if (sc->resolution)
		vector_destroy(sc->resolution);
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
