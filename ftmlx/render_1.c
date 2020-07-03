/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/03 17:41:25 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

int		collision_pix(t_mrt *mrt, int x, int y)
{
	t_prm	*p;

	p = mrt->scn->primitives;
	while (p)
	{
		p = p->nx;
	}
	(void)x;
	(void)y;
	return (0);
}

void	render_prepare(t_mrt *mrt)
{
	int		res_base;
	int		res_m;
	int		res_n;
	int		x;
	int		y;
	t_vec	*vec;

	res_base = mrt->i.height > mrt->i.width ? mrt->i.height : mrt->i.width;
//	step = 2 * tan(mrt->scn->cam_active.fov / 2) / (double)res_base;
	if (mrt->i.height >= mrt->i.width)
	{
		res_m = mrt->i.height;
		res_n = ft_trig(mrt->i.height, mrt->i.width, res_m);
	}
	else
	{
		res_n = mrt->i.width;
		res_m = ft_trig(mrt->i.width, mrt->i.height, res_n);
	}
	mrt->pjt = ft_mvec();
	y = 1;
	DEBINT2("res", res_m, res_n);
	while (y <= res_n)
	{
		x = 1;
		while (x <= res_m)
		{
			vec = ft_vec(3, 1, 2, 3);
			ft_vm_add(mrt->pjt, x, y, vec);
			x++;
		}
		y++;
	}
	DEBMATVEC("matvec", mrt->pjt);
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
//			if (collision_pix(mrt, x, y))
				ft_pix(mrt, x, y, (x * y / 2) << 16);
				if ((FLIP_PARTS != 1) && (pix_count++ % (int)rtflip == 0))
					flip(mrt);
			x++;
		}
		y++;
	}
	return ;
}

void	flip(t_mrt *mrt)
{
	mlx_put_image_to_window(mrt->mlx, mrt->win, mrt->img, 0, 0);
	return ;
}
