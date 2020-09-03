/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_faces_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:54:39 by fde-capu          #+#    #+#             */
/*   Updated: 2020/09/02 19:59:55 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	cam_faces_y(t_cam *cam, t_vec **pix)
{
	t_mat	*trf;

	trf = vector_vector_rotation_matrix(g_y, g_z);
	vector_transform(pix, trf);
	trf = vectorx(trf, vector_vector_rotation_matrix(cam->n, g_z));
	vector_transform(pix, trf);
	vector_destroy(trf);
	return ;
}

void	cam_faces_minus_y(t_cam *cam, t_vec **pix)
{
	t_mat	*trf;

	vector_multiply_element(*pix, 1, -1.0);
	trf = vector_vector_rotation_matrix(g_y, g_z);
	vector_transform(pix, trf);
	trf = vectorx(trf, vector_vector_rotation_matrix(cam->n, g_z));
	vector_transform(pix, trf);
	vector_destroy(trf);
	return ;
}

void	cam_faces_minus_x(t_cam *cam, t_vec **pix)
{
	t_mat	*trf;

	trf = vector_vector_rotation_matrix(g_y, g_x);
	vector_transform(pix, trf);
	trf = vectorx(trf, vector_vector_rotation_matrix(g_z, g_x));
	vector_transform(pix, trf);
	trf = vectorx(trf, vector_vector_rotation_matrix(cam->n, g_z));
	vector_transform(pix, trf);
	vector_destroy(trf);
	return ;
}

void	cam_faces_x(t_cam *cam, t_vec **pix)
{
	t_mat	*trf;

	trf = vector_vector_rotation_matrix(g_y, g_x);
	vector_transform(pix, trf);
	trf = vectorx(trf, vector_vector_rotation_matrix(g_z, g_x));
	vector_transform(pix, trf);
	trf = vectorx(trf, vector_vector_rotation_matrix(cam->n, g_z));
	vector_transform(pix, trf);
	vector_destroy(trf);
	return ;
}

void	cam_faces_minus_z(t_cam *cam, t_vec **pix)
{
	t_mat	*trf;

	vector_multiply_element(*pix, 2, -1.0);
	trf = vector_vector_rotation_matrix(cam->n, g_y);
	vector_transform(pix, trf);
	vector_destroy(trf);
	return ;
}
