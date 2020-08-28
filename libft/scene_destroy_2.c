/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_destroy_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:31:35 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 15:31:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		scn_free_list_tri(t_tri *lst)
{
	if (lst->nx)
		scn_free_list_tri(lst->nx);
	triangle_destroy(lst);
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
	vector_destroy(g_x);
	vector_destroy(g_y);
	vector_destroy(g_z);
	return (1);
}
