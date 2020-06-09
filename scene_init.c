/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:40:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 14:43:05 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_amb_light	amb_light_init(double f, t_rgb rgb)
{
	t_amb_light	o;

	o.f = f;
	o.rgb = rgb;
	return (o);
}
