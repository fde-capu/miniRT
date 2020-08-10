/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/10 13:21:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	prepare_project_space(t_mrt *mrt)
{
	int		i;
	int		j;

	pjt_init(mrt);
	j = 1;
	while (j <= mrt->window.height)
	{
		i = 1;
		while (i <= mrt->window.width)
		{
			pjt_xyz(mrt, i, j);
			i++;
		}
		j++;
	}
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
