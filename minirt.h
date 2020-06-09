/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:38:51 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 00:35:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include			"minilibx-linux/mlx.h"
# include			"libft/libft.h"
# include			<sys/types.h>
# include			<sys/stat.h>
# include			<fcntl.h>

# define WIN_TITLE	":: mrt : minirt : miniRT :: by fde-capu :: 42SP ::"
# define TRIM_SET	"\t "
# define FILE_ERROR	"Error loading file."

typedef struct		scene
{
	i2d				r;
	struct scene	*nx;
}					scn;

scn					g_scn;

int					load_rt_file(char *fn, scn sc);
void				rt_line_interpret(char *ln, scn sc);
#endif
