/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pjt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:10:58 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/10 17:17:22 by fde-capu         ###   ########.fr       */
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

void	pjt_xyz2(t_mrt *mrt, int i, int j)
{
	t_vec	*pix;
	t_vec	*center;
	double	factor;
	double	fov_size[2];
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
