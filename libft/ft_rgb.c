/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:30:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/25 17:21:18 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rgb			ft_rgb(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
	t_rgb	o;

	o.a = a;
	o.r = r;
	o.g = g;
	o.b = b;
	return (o);
}

t_rgb			ft_atorgb(char *str)
{
	char			**rgb;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	rgb = ft_split(str, ',');
	r = (unsigned char)ft_atoi(rgb[0]);
	g = (unsigned char)ft_atoi(rgb[1]);
	b = (unsigned char)ft_atoi(rgb[2]);
	ft_strfree2d(rgb);
	return (ft_rgb(0, r, g, b));
}

t_rgb			ft_atoargb(char *str)
{
	char			**rgb;
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	rgb = ft_split(str, ',');
	a = (unsigned char)ft_atoi(rgb[0]);
	r = (unsigned char)ft_atoi(rgb[1]);
	g = (unsigned char)ft_atoi(rgb[2]);
	b = (unsigned char)ft_atoi(rgb[3]);
	ft_strfree2d(rgb);
	return (ft_rgb(a, r, g, b));
}

char			*ft_rgbtoa(t_rgb rgb)
{
	char	*o;

	o = ft_uctoa(rgb.a);
	o = ft_strcatxl(o, ",");
	o = ft_strcatx(o, ft_uctoa(rgb.r));
	o = ft_strcatxl(o, ",");
	o = ft_strcatx(o, ft_uctoa(rgb.g));
	o = ft_strcatxl(o, ",");
	o = ft_strcatx(o, ft_uctoa(rgb.b));
	return (o);
}

int	ft_rgbtoi(t_rgb rgb)
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
	o += (rgb.b);
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
