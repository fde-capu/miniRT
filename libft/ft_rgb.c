/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:30:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/24 16:00:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rgb	ft_rgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	t_rgb	o;

	o.t = t;
	o.r = r;
	o.g = g;
	o.b = b;
	return (o);
}

t_rgb	ft_atorgb(char *str)
{
	char			**rgb;
	unsigned char	t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	rgb = ft_split(str, ',');
	t = (unsigned char)ft_atoi(rgb[0]);
	r = (unsigned char)ft_atoi(rgb[1]);
	g = (unsigned char)ft_atoi(rgb[2]);
	b = (unsigned char)ft_atoi(rgb[3]);
	ft_strfree2d(rgb);
	return (ft_rgb(t, r, g, b));
}

char	*ft_rgbtoa(t_rgb rgb)
{
	char	*o;

	o = ft_uctoa(rgb.t);
	o = ft_strcatxl(o, DIV);
	o = ft_strcatx(o, ft_uctoa(rgb.r));
	o = ft_strcatxl(o, DIV);
	o = ft_strcatx(o, ft_uctoa(rgb.g));
	o = ft_strcatxl(o, DIV);
	o = ft_strcatx(o, ft_uctoa(rgb.b));
	return (o);
}

int		ft_rgbtoi(t_rgb rgb)
{
	int	o;

	o = 0;
	o += (rgb.t << 24);
	o += (rgb.r << 16);
	o += (rgb.g << 8);
	o += (rgb.b);
	return (o);
}

t_rgb	ft_itorgb(int i)
{
	t_rgb	rgb;

	rgb.t = (i & 0xFF000000) >> 24;
	rgb.r = (i & 0x00FF0000) >> 16;
	rgb.g = (i & 0X0000FF00) >> 8;
	rgb.b = (i & 0x000000FF) >> 0;
	return (rgb);
}
