/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 09:35:03 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 16:30:53 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	write_mrtitobmp(t_mrt *mrt, int fp)
{
	char	*h;
	int		x;
	int		y;

	render(mrt);
	x = mrt->i.height;
	while (x > 0)
	{
		y = 1;
		while (y <= mrt->i.width)
		{
			h = mrt_cursor(mrt, x, y);
			write(fp, h, sizeof(int));
			y++;
		}
		x--;
	}
	return ;
}

void	write_bmpheads(t_bmp *bmp, int fp)
{
	write(fp, &bmp->file_header.bftype, sizeof((t_bmfh *)0)->bftype);
	write(fp, &bmp->file_header.bfsize, sizeof((t_bmfh *)0)->bfsize);
	write(fp, &bmp->file_header.zeros1, sizeof((t_bmfh *)0)->zeros1);
	write(fp, &bmp->file_header.zeros2, sizeof((t_bmfh *)0)->zeros2);
	write(fp, &bmp->file_header.bfoffs, sizeof((t_bmfh *)0)->bfoffs);
	write(fp, &bmp->info_header.bisize, sizeof((t_bmih *)0)->bisize);
	write(fp, &bmp->info_header.biwidth, sizeof((t_bmih *)0)->biwidth);
	write(fp, &bmp->info_header.biheight, sizeof((t_bmih *)0)->biheight);
	write(fp, &bmp->info_header.biplanes, sizeof((t_bmih *)0)->biplanes);
	write(fp, &bmp->info_header.bpp, sizeof((t_bmih *)0)->bpp);
	write(fp, &bmp->info_header.bicompress, sizeof((t_bmih *)0)->bicompress);
	write(fp, &bmp->info_header.bisizeimg, sizeof((t_bmih *)0)->bisizeimg);
	write(fp, &bmp->info_header.bixppmeter, sizeof((t_bmih *)0)->bixppmeter);
	write(fp, &bmp->info_header.biyppmeter, sizeof((t_bmih *)0)->biyppmeter);
	write(fp, &bmp->info_header.binumofcolors, \
		sizeof((t_bmih *)0)->binumofcolors);
	write(fp, &bmp->info_header.biimportantcolors, \
		sizeof((t_bmih *)0)->biimportantcolors);
}

void	*save_mrttobmp(t_mrt *mrt, char *fn)
{
	int		size;
	t_bmp	*bmp;
	int		fp;

	size = 14 + 40 + ((mrt->i.width * mrt->i.height) * sizeof(int));
	bmp = ft_calloc(sizeof(t_bmp), 1);
	bmp->file_header.bftype = 19778;
	bmp->file_header.bfsize = size;
	bmp->file_header.bfoffs = 14 + 40;
	bmp->info_header.bisize = 40;
	bmp->info_header.biwidth = vector_get_element(mrt->scn->resolution, 1);
	bmp->info_header.biheight = vector_get_element(mrt->scn->resolution, 2);
	bmp->info_header.biplanes = 1;
	bmp->info_header.bpp = mrt->i.bpp;
	if ((fp = open(fn, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
		die(mrt, OPEN_W_ERROR, ERR_OPEN_W);
	write_bmpheads(bmp, fp);
	write_mrtitobmp(mrt, fp);
	close(fp);
	free(bmp);
	ft_putstr(MSG_SAVED);
	ft_putstr(SAVE_FN);
	ft_putstr("\n");
	return (0);
}
