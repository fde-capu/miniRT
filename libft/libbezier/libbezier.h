/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbezier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 15:16:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/02 10:35:34 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBEZIER_H
# define LIBBEZIER_H

# include "../libft.h"

typedef	struct	s_cubic_bezier
{
	t_vec		*a;
	t_vec		*b;
	t_vec		*c;
	t_vec		*d;
}				t_cub_bez;

t_vec			*linint(t_vec *a, t_vec *b, double t);
t_vec			*cubic_bez(t_cub_bez bez, double t);
t_cub_bez		bez_init(t_vec *a, t_vec *b, t_vec *c, t_vec *d);

#endif
