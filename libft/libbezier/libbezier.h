/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbezier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 15:16:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 12:34:21 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBEZIER_H
# define LIBBEZIER_H

# include "../libft.h"

typedef	struct	s_cubic_bezier
{
	t_d2d		a;
	t_d2d		b;
	t_d2d		c;
	t_d2d		d;
}				t_cub_bez;

t_d2d			linint(t_d2d a, t_d2d b, double t);
t_d2d			cubic_bez(t_cub_bez bez, double t);
t_cub_bez		bez_init(t_d2d a, t_d2d b, t_d2d c, t_d2d d);

#endif
