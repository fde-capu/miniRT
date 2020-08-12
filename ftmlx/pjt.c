/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pjt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:10:58 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/12 09:23:28 by fde-capu         ###   ########.fr       */
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

void	pjt_xyz(t_mrt *mrt, int i, int j)
{
	t_vec	*pcs;
	double	pscreen[2];
	double	pcam[2];

	pscreen[X] = 2 * ((j + 0.5) / mrt->window.width) - 1;
	pcam[X] = (2 * pscreen[X] - 1) * mrt->window.width / \
		mrt->window.height * tan(degtorad(mrt->scn->cam_active->fov) / 2);
	pscreen[Y] = 1 - 2 * ((i + 0.5) / mrt->window.height);
	pcam[Y] = (1 - 2 * pscreen[Y]) * \
		tan(degtorad(mrt->scn->cam_active->fov) / 2);
	pcs = vector_build(3, pcam[X], pcam[Y], (double)1);
	pcs = vectorx(pcs, vector_sum(pcs, mrt->scn->cam_active->o));
	matrix_put_element(mrt->pjt[X], i, j, vector_get_element(pcs, 1));
	matrix_put_element(mrt->pjt[Y], i, j, vector_get_element(pcs, 2));
	matrix_put_element(mrt->pjt[Z], i, j, vector_get_element(pcs, 3));
	vector_destroy(pcs);
	return ;
}

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

	v3 = vector_cross_product(v1, v2);
	vector_normalize(v3);
	v4 = vector_cross_product(v3, v1);
	m1 = matrix_of_vectors_transposed(v1, v4, v3);
	cos = vector_dot_product(v2, v1);
	sin = vector_dot_product(v2, v4);
	DEBDBL2("cos sin", cos, sin);
	m2 = matrix_build(3, 3, cos, -sin, 0.0, sin, cos, 0.0, 0.0, 0.0, 1.0);
	DEBMAT("m2", m2);
	DEBMAT("m1", m1);
	ret = matrix_matrix_multiply(m2, m1);
	DEBMAT("ret", ret);
	m1i = matrix_inverse(m1);
	DEBMAT("m1i", m1i);
	ret = matrixx(ret, matrix_matrix_multiply(m1i, ret));
	vector_destroy(v3);
	vector_destroy(v4);
	matrix_destroy(m1);
	matrix_destroy(m2);
	matrix_destroy(m1i);
	return (ret);
}

void	pjt_xyz2(t_mrt *mrt, int i, int j)
{
	t_vec	*pix;
	t_vec	*center;
	double	factor;
	double	fov_size[2];
	t_vec	*up;
	t_mat	*rvv;
//	double	aspect;

	center = vector_build(3, (mrt->window.height + 1.0) / 2.0, (mrt->window.width + 1.0) / 2.0, 0.0);
	if (mrt->window.width > mrt->window.height)
	{
		fov_size[Y] = 2 * tan(degtorad(mrt->scn->cam_active->fov) / 2);
		fov_size[X] = ft_trig(mrt->window.height, fov_size[Y], mrt->window.width);
	}
	else
	{
		fov_size[X] = 2 * tan(degtorad(mrt->scn->cam_active->fov) / 2);
		fov_size[Y] = ft_trig(mrt->window.width, fov_size[X], mrt->window.height);
	}
	factor = ft_trig(fov_size[Y], 1, mrt->window.width);
	pix = vector_build(3, (double)i, (double)j, (double)0);
	pix = vectorx(pix, vector_subtract(pix, center));
	pix = vectorx(pix, vector_scalar_multiply(pix, factor));
	up = vector_build(3, 0.0, 0.0, 1.0);
	rvv = rotvv(up, mrt->scn->cam_active->p);
	vector_destroy(up);
//	aspect = mrt->window.width / mer->window.height;
//	fov_size = 
//	pix = vectotx(pix, vector_scale(pix, fov_size / 2));
	matrix_put_element(mrt->pjt[X], i, j, vector_get_element(pix, 1));
	matrix_put_element(mrt->pjt[Y], i, j, vector_get_element(pix, 2));
	matrix_put_element(mrt->pjt[Z], i, j, vector_get_element(pix, 3));
	vector_destroy(center);
	vector_destroy(pix);
	return ;
}
