/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:46:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 15:22:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_i2d	ft_i2d(int x, int y)
{
	t_i2d	o;

	o.x = x;
	o.y = y;
	return (o);
}

t_d3d	ft_d3d(double x, double y, double z)
{
	t_d3d	o;

	o.x = x;
	o.y = y;
	o.z = z;
	return (o);
}

t_vec	ft_vec(double x, double y, double z)
{
	return (ft_vector(x, y, z));
}

t_vec	ft_vector(double x, double y, double z)
{
	return ((t_vec)ft_d3d(x, y, z));
}
