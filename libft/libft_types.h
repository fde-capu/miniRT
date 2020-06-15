/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:40:42 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 09:07:46 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_int2d
{
	int				x;
	int				y;
}					t_i2d;

typedef struct		s_int3d
{
	int				x;
	int				y;
	int				z;
}					t_i3d;

typedef struct		s_double2d
{
	double			x;
	double			y;
}					t_d2d;

typedef struct		s_double3d
{
	double			x;
	double			y;
	double			z;
}					t_d3d;
typedef t_d3d		t_vec;

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef unsigned char	t_bol;

#endif
