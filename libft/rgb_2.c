/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:00:41 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 15:06:08 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_rgbtoi(t_rgb rgb)
{
	int	o;

	o = 0;
	o += (rgb.r << 16);
	o += (rgb.g << 8);
	o += (rgb.b);
	return (o);
}

unsigned int	ft_argbtoi(t_rgb rgb)
{
	unsigned int	o;

	o = 0;
	o += (rgb.a << 24);
	o += (rgb.r << 16);
	o += (rgb.g << 8);
	o += (rgb.b << 0);
	return (o);
}

t_rgb			ft_itobgra(unsigned int i)
{
	t_rgb	rgb;

	rgb.b = (i & 0xFF000000) >> 24;
	rgb.g = (i & 0x00FF0000) >> 16;
	rgb.r = (i & 0X0000FF00) >> 8;
	rgb.a = (i & 0x000000FF) >> 0;
	return (rgb);
}

t_rgb			ft_itoargb(unsigned int i)
{
	t_rgb	rgb;

	rgb.a = (i & 0xFF000000) >> 24;
	rgb.r = (i & 0x00FF0000) >> 16;
	rgb.g = (i & 0X0000FF00) >> 8;
	rgb.b = (i & 0x000000FF) >> 0;
	return (rgb);
}
