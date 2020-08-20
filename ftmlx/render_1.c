/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 18:27:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

/*
**      v v v d   rgb  d  d i     v v v
** cam	o p n fov
** lht	o     f   rgb
** prm  o   n     rgb  h  d type
** tri      n     rgb             a b c
*/

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
			pjt_pixtocam(mrt, i, j);
			i++;
		}
		j++;
	}
	return ;
}

void	render(t_mrt *mrt)
{
	int		x;
	int		y;
	int		pix_count;
	double	rtflip;

	ft_putstr(MSG_RENDERING);
	prepare_project_space(mrt);
	DEB("project space done!");
	pix_count = 0;
	rtflip = (1.0 / (double)FLIP_PARTS) * mrt->i.height * mrt->i.width;
	y = 1;
	while (y <= mrt->i.height)
	{
		x = 1;
		while (x <= mrt->i.width)
		{
			if (collision_pix(mrt, x, y))
			{
				ft_pix(mrt, x, y, (x * y / 2) << 8);
			}
			else
			{
				// compute color at intersection point
				ft_pix(mrt, x, y, (x * y / 2) << 16);
			}
			if ((FLIP_PARTS != 1) && (pix_count++ % (int)rtflip == 0))
				flip(mrt);
			x++;
		}
		y++;
	}
	return ;
}
