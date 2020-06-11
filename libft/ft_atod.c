/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:53:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/11 16:08:51 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	char	*n;
	int		lod;
	int		rod;
	double	dec;
	char	*snc;

	if ((!str) || (!*str))
		return (0.0);
	n = ft_strdup(str);
	lod = ft_atoi(n);
	snc = ft_strnchr(n, '.');
	rod = ft_atoi(snc && ft_isdigit(*(snc + 1)) ? snc + 1 : 0);
	dec = rod / (ft_pow(10, ft_countdigits(rod)));
	free(n);
	return (lod + dec);
}

/*
** ft_atod3d aka ft_atovec
*/

t_d3d	ft_atod3d(const char *str)
{
	char	**xyz;
	double	x;
	double	y;
	double	z;

	xyz = ft_split(str, ',');
	x = ft_atod(xyz[0]);
	y = ft_atod(xyz[1]);
	z = ft_atod(xyz[2]);
	ft_strfree2d(xyz);
	return (ft_d3d(x, y, z));
}

char	*ft_d3dtoa(t_d3d vec)
{
	char	*o;

	o = ft_dtoa(vec.x);
	o = ft_strcatxl(o, DIV);
	o = ft_strcatx(o, ft_dtoa(vec.x));
	o = ft_strcatxl(o, DIV);
	o = ft_strcatx(o, ft_dtoa(vec.y));
	o = ft_strcatxl(o, DIV);
	o = ft_strcatx(o, ft_dtoa(vec.z));
	return (o);
}

t_vec	ft_atovec(const char *str)
{
	return ((t_vec)ft_atod3d(str));
}
