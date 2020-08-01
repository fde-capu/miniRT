/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/01 14:12:25 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	prepare_project_space(t_mrt *mrt)
{
	int		i;
	int		j;
	double	pndc[2];
	double	pscreen[2];
	double	imgaspect;
	double	pcam[2];
	t_vec	*pcamspace;

	mrt->pjt[X] = matrix_empty(mrt->window.height, mrt->window.width);
	mrt->pjt[Y] = matrix_empty(mrt->window.height, mrt->window.width);
	mrt->pjt[Z] = matrix_empty(mrt->window.height, mrt->window.width);
	pcamspace = vector_new();
	imgaspect = mrt->window.width / mrt->window.height;
	j = 1;
	while (j <= mrt->window.height)
	{
		pndc[X] = (j + 0.5) / mrt->window.width;
		pscreen[X] = 2 * pndc[X] - 1;
		pcam[X] = (2 * pscreen[X] - 1) * imgaspect * tan(degtorad(mrt->scn->cam_active->fov) / 2);
		i = 1;
		while (i <= mrt->window.width)
		{
			pndc[Y] = (i + 0.5) / mrt->window.height;
			pscreen[Y] = 1 - 2 * pndc[Y];
			pcam[Y] = (1 - 2 * pscreen[Y]) * tan(degtorad(mrt->scn->cam_active->fov) / 2);
			pcamspace = vectorx(pcamspace, vector_build(3, pcam[X], pcam[Y], 5.2));
			pcamspace = vectorx(pcamspace, vector_sum(pcamspace, mrt->scn->cam_active->o));
			matrix_put_element(mrt->pjt[X], i, j, vector_get_element(pcamspace, X));
			matrix_put_element(mrt->pjt[Y], i, j, vector_get_element(pcamspace, Y));
			matrix_put_element(mrt->pjt[Z], i, j, vector_get_element(pcamspace, Z));
			i++;
		}
		j++;
	}
	matrix_destroy(pcamspace);
}

/*
**
**      v v v d   rgb  d  d i     v v v
** cam	o p n fov
** lht	o     f   rgb
** prm  o   n     rgb  h  d type
** tri      n     rgb             a b c
**
*/

void	world_to_view(void)
{
	// to do
}

void	prepare_view_space(void)
{
	// to do
}

void	render_prepare(t_mrt *mrt)
{
//	construct_base_transforms();
//	prepare_view_space(mrt);
	prepare_project_space(mrt);
	return ;
}

void	render(t_mrt *mrt)
{
	int		x;
	int		y;
	int		pix_count;
	double	rtflip;
	
	ft_putstr(MSG_RENDERING);
	render_prepare(mrt);
	pix_count = 0;
	rtflip = (1.0 / (double)FLIP_PARTS) * mrt->i.height * mrt->i.width;
	y = 1;
	while (y <= mrt->i.height)
	{
		x = 1;
		while (x <= mrt->i.width)
		{
			// cast ray from eye
			// 
//			if (collision_pix(mrt, x, y))
//			{
				// compute color at intersection point
				ft_pix(mrt, x, y, (x * y / 2) << 16);
//			}
			if ((FLIP_PARTS != 1) && (pix_count++ % (int)rtflip == 0))
				flip(mrt);
			x++;
		}
		y++;
	}
	return ;
}
