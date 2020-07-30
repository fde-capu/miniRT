/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 08:37:06 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/30 16:21:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

double	hipo(double c1, double c2)
{
	return (sqrt((c1 * c1) + (c2 * c2)));
}

double	radtodeg(double rad)
{
	return (rad * 180 / M_PI);
}

double	degtorad(double deg)
{
	return (deg * M_PI / 180);
}
