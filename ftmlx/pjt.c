/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pjt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:10:58 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 19:28:21 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	pjt_init(t_mrt *mrt)
{
	mrt->pjt[X] = matrix_empty(mrt->window.height, mrt->window.width);
	mrt->pjt[Y] = matrix_empty(mrt->window.height, mrt->window.width);
	mrt->pjt[Z] = matrix_empty(mrt->window.height, mrt->window.width);
	return ;
}

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

t_mat	*vector_vector_rotation_matrix(t_vec *v1, t_vec *v2)
{
	double	theta;
	t_vec	*axis;
	t_mat	*rvv;

	theta = vector_vector_angle_rad(v1, v2);
	axis = vector_cross_product(v1, v2);
	rvv = axis_angle_rotation(axis, theta);
	vector_destroy(axis);
	return (rvv);
}

t_vec	*pix_film(t_mrt *mrt, int i, int j)
{
	t_vec			*pix;
	t_vec	*center;
	double	factor;
	double	fov_size[2];

	center = vector_build(3, (mrt->window.height + 1.0) / 2.0, \
		(mrt->window.width + 1.0) / 2.0, 0.0);
	if (mrt->window.width > mrt->window.height)
	{
		fov_size[Y] = 2 * tan(degtorad(mrt->scn->cam_active->fov) / 2);
		fov_size[X] = \
			ft_trig(mrt->window.height, fov_size[Y], mrt->window.width);
	}
	else
	{
		fov_size[X] = 2 * tan(degtorad(mrt->scn->cam_active->fov) / 2);
		fov_size[Y] = \
			ft_trig(mrt->window.width, fov_size[X], mrt->window.height);
	}
	factor = ft_trig(fov_size[Y], 1, mrt->window.width);
	pix = vector_build(3, (double)i, (double)j, (double)0);
	pix = vectorx(pix, vector_subtract(pix, center));
	pix = vectorx(pix, vector_scalar_multiply(pix, factor));
	vector_destroy(center);
	return (pix);
}

t_vec	*pjt_pixtocam(t_mrt *mrt, int i, int j)
{
	t_vec			*pix;
	t_mat	*rvv[3];
	t_vec	*tmp;

	pix = pix_film(mrt, i, j);
	tmp = vector_scalar_multiply(g_y, -1.0);
	rvv[0] = vector_vector_rotation_matrix(tmp, mrt->scn->cam_active->p);
	vector_transform(&pix, rvv[0]);
	rvv[1] = vector_vector_rotation_matrix(mrt->scn->cam_active->p, \
		mrt->scn->cam_active->n);
	vector_transform(&pix, rvv[1]);
	if (vector_parallel(mrt->scn->cam_active->p, g_y))
	{
		rvv[2] = axis_angle_rotation(g_y, degtorad(180.0));
		vector_transform(&pix, rvv[2]);
	}
	pix = vectorx(pix, vector_translate(pix, mrt->scn->cam_active->o));
	pix = vectorx(pix, vector_translate(pix, mrt->scn->cam_active->p));
//	matrix_put_element(mrt->pjt[X], i, j, vector_get_element(pix, 1));
//	matrix_put_element(mrt->pjt[Y], i, j, vector_get_element(pix, 2));
//	matrix_put_element(mrt->pjt[Z], i, j, vector_get_element(pix, 3));
//	vector_destroy(pix);
//	ft_putchar('.');
	vector_destroy(tmp);
	vector_destroy(rvv[0]);
	vector_destroy(rvv[1]);
	vector_destroy(rvv[2]);
	return (pix);
}
