/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pjt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:10:58 by fde-capu          #+#    #+#             */
/*   Updated: 2020/09/02 19:55:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

t_mat	*axis_angle_rotation(t_vec *axis, double theta)
{
	double	cosine;
	double	sine;
	double	ux;
	double	uy;
	double	uz;

	cosine = cos(theta);
	sine = sin(theta);
	ux = vector_get_element(axis, 1);
	uy = vector_get_element(axis, 2);
	uz = vector_get_element(axis, 3);
	return (matrix_build(3, 3, \
		((ux * ux) + (ux * ux * -cosine) + cosine),
		((uy * ux) + (uy * ux * -cosine) + (uz * sine)),
		((uz * ux) + (uz * ux * -cosine) - (uy * sine)),
		((ux * uy) + (ux * uy * -cosine) - (uz * sine)),
		((uy * uy) + (uy * uy * -cosine) + cosine),
		((uz * uy) + (uz * uy * -cosine) + (ux * sine)),
		((ux * uz) + (ux * uz * -cosine) + (uy * sine)),
		((uy * uz) + (uy * uz * -cosine) - (ux * sine)),
		((uz * uz) + (uz * uz * -cosine) + cosine)));
}

t_vec	*pix_film(t_mrt *mrt, int i, int j)
{
	t_vec	*pix;
	t_vec	*center;
	double	factor;
	double	fov_size[2];

	center = vector_build(3, (mrt->window.width + 1.0) \
		/ 2.0, (mrt->window.height + 1.0) / 2.0, 0.0);
	if (mrt->window.width > mrt->window.height)
	{
		fov_size[Y] = 2.0 * tan(degtorad(mrt->scn->cam_active->fov) / 2.0);
		fov_size[X] = ft_trig(mrt->window.height, \
			fov_size[Y], mrt->window.width);
	}
	else
	{
		fov_size[X] = 2.0 * tan(degtorad(mrt->scn->cam_active->fov) / 2.0);
		fov_size[Y] = ft_trig(mrt->window.width, \
			fov_size[X], mrt->window.height);
	}
	factor = fov_size[Y] / mrt->window.width;
	pix = vector_build(3, (double)i, (double)j, (double)0);
	pix = vectorx(pix, vector_subtract(pix, center));
	pix = vectorx(pix, vector_scalar_multiply(pix, factor));
	vector_destroy(center);
	return (pix);
}

void	cam_faces_z(t_cam *cam, t_vec **pix)
{
	t_mat	*trf;

	trf = (t_mat *)vector_scalar_multiply(g_y, -1.0);
	trf = vector_vector_rotation_matrix(cam->n, trf);
	vector_transform(pix, trf);
	vector_destroy(trf);
	return ;
}

t_vec	*pjt_pixtocam(t_mrt *mrt, int i, int j)
{
	t_vec	*pix;
	t_cam	*cam;

	cam = mrt->scn->cam_active;
	pix = pix_film(mrt, i, j);
	if (vector_dot_product(cam->p, g_y) > 0.0)
		cam_faces_y(cam, &pix);
	if (vector_dot_product(cam->p, g_y) < 0.0)
		cam_faces_minus_y(cam, &pix);
	if (vector_dot_product(cam->p, g_x) < 0.0)
		cam_faces_minus_x(cam, &pix);
	if (vector_dot_product(cam->p, g_x) > 0.0)
		cam_faces_x(cam, &pix);
	if (vector_dot_product(cam->p, g_z) < 0.0)
		cam_faces_minus_z(cam, &pix);
	if (vector_dot_product(cam->p, g_z) > 0.0)
		cam_faces_z(cam, &pix);
	pix = vectorx(pix, \
		vector_translate(pix, cam->o));
	pix = vectorx(pix, \
		vector_translate(pix, cam->p));
	return (pix);
}
