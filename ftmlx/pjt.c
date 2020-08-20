/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pjt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:10:58 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/18 17:02:29 by fde-capu         ###   ########.fr       */
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

/*
** inspired by Zhu
** http://steve.hollasch.net/cgindex/math/rotvecs.html
*/

t_mat	*rotvv(t_vec *v1, t_vec *v2)
{
	t_vec	*v3;
	t_vec	*v4;
	t_mat	*m1;
	t_mat	*m2;
	double	cos;
	double	sin;
	t_mat	*ret;
	t_mat	*m1i;

	if (vector_vector_angle_deg(v1, v2) == 0)
		return (matrix_identity(3));
	if (vector_vector_angle_deg(v1, v2) == 180)
	{
		ret = matrix_identity(3);
		ret = matrixx(ret, matrix_scalar_multiply(ret, -1.0));
		return (ret);
	}
	v3 = vector_cross_product(v1, v2);
	vector_normalize(v3);
	v4 = vector_cross_product(v3, v1);
	m1 = matrix_of_vectors_transposed(v1, v4, v3);
	cos = vector_dot_product(v2, v1);
	sin = vector_dot_product(v2, v4);
	m2 = matrix_build(3, 3, cos, -sin, 0.0, sin, cos, 0.0, 0.0, 0.0, 1.0);
	ret = matrix_matrix_multiply(m2, m1);
	m1i = matrix_inverse(m1);
	ret = matrixx(ret, matrix_matrix_multiply(m1i, ret));
	vector_destroy(v3);
	vector_destroy(v4);
	matrix_destroy(m1);
	matrix_destroy(m2);
	matrix_destroy(m1i);
	return (ret);
}

t_vec	*pix_film(t_mrt *mrt, int i, int j)
{
	t_vec	*pix;
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

void	pjt_pixtocam(t_mrt *mrt, int i, int j)
{
	t_vec	*pix;
	t_mat	*rvv;
	t_vec	*screen_up;

	pix = pix_film(mrt, i, j);
	screen_up = vector_copy(g_y);
	rvv = rotvv(screen_up, mrt->scn->cam_active->p);
	DEBVEC("pix1", pix);
	vector_transform(&pix, rvv);
	DEBVEC("pix2", pix);
	rvv = matrixx(rvv, rotvv(mrt->scn->cam_active->p, mrt->scn->cam_active->n));
	vector_transform(&pix, rvv);
	DEBVEC("pix3", pix);
	DEB("");
	vector_destroy(rvv);
	matrix_put_element(mrt->pjt[X], i, j, vector_get_element(pix, 1));
	matrix_put_element(mrt->pjt[Y], i, j, vector_get_element(pix, 2));
	matrix_put_element(mrt->pjt[Z], i, j, vector_get_element(pix, 3));
	vector_destroy(pix);
	vector_destroy(screen_up);
	return ;
}
