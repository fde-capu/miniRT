/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 16:44:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	prepare_project_space(t_mrt *mrt)
{
	int		res_base;
	int		step_base;
	int		step_y;
	int		step_x;
	int		x;
	int		y;
	t_vec	*vec;

	res_base = mrt->i.height > mrt->i.width ? mrt->i.height : mrt->i.width;
	step_base = 2 * tan(mrt->scn->cam_active->fov / 2) / (double)res_base;
	if (mrt->i.height >= mrt->i.width)
	{
		step_y = step_base;
		step_x = ft_trig(mrt->i.height, mrt->i.width, step_y);
	}
	else
	{
		step_x = step_base;
		step_y = ft_trig(mrt->i.width, mrt->i.height, step_x);
	}
	mrt->pjt = matvec_new();
	y = 1;
	DEBINT2("res", step_y, step_x);
	while (y <= step_x)
	{
		x = 1;
		while (x <= step_y)
		{
			vec = vector_sum(mrt->scn->cam_active->o, mrt->scn->cam_active->p);
			matvec_insert_at_pos(mrt->pjt, x, y, vec);
			x++;
		}
		y++;
	}
	DEBMATVEC("matvec", mrt->pjt);
	return ;
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
//	prepare_project_space(mrt);
(void)mrt;
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
