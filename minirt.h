/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:38:51 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 14:43:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIN_TITLE	":: mrt : minirt : miniRT :: by fde-capu :: 42SP ::"
# define FILE_ERROR	"Error loading file."

typedef struct		s_amb_light
{
	double			f;
	t_rgb			rgb;
}					t_amb_light;

typedef struct		s_scene
{
	t_i2d			r;
	t_amb_light		a;
	struct scene	*nx;
}					t_scn;

t_scn				g_scn;

int					load_rt_file(char *fn, t_scn *sc);
void				rt_line_interpret(char *ln, t_scn *sc);
int					rt_command(char *str, char *com);
t_amb_light			amb_light_init(double f, t_rgb rgb);

#endif
