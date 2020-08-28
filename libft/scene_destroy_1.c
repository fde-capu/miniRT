/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_destroy_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:31:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 15:31:53 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	vector_destroy(lst->left);
	free(lst);
	return ;
}

void		primitive_destroy(t_prm *lst)
{
	vector_destroy(lst->o);
	vector_destroy(lst->n);
	free(lst);
	return ;
}

void		scn_free_list_prm(t_prm *lst)
{
	if (lst->nx)
		scn_free_list_prm(lst->nx);
	primitive_destroy(lst);
	return ;
}

void		triangle_destroy(t_tri *lst)
{
	vector_destroy(lst->a);
	vector_destroy(lst->b);
	vector_destroy(lst->c);
	vector_destroy(lst->n);
	free(lst);
	return ;
}
