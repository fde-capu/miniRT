/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:38:51 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 13:42:31 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "ftmlx/ftmlx.h"
# include "minilibx-linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define WIN_TITLE	":: mrt : minirt : miniRT :: by fde-capu :: 42SP ::"

typedef struct		s_sphere
{
	t_d3d			o;
	double			d;
	t_rgb			rgb;
	struct s_sphere	*nx;
}					t_sp;

typedef struct		s_camera
{
	t_d3d			o;
	t_vec			p;
	double			fov;
	struct s_camera	*nx;
}					t_cam;

typedef struct		s_amb_light
{
	double			f;
	t_rgb			rgb;
}					t_amb_light;

typedef struct		s_light
{
	t_d3d			o;
	double			f;
	t_rgb			rgb;
	struct s_light	*nx;
}					t_light;

typedef struct		s_scene
{
	t_i2d			resolution;
	t_amb_light		ambient;
	t_cam			*cam_active;
	t_cam			*cam_list;
	t_light			*lights;
	t_sp			*spheres;
}					t_scn;

t_scn				*g_scn;

int					load_rt_file(char *fn, t_scn *sc);
void				rt_line_interpret(char *ln, t_scn *sc);
int					rt_command(char *str, char *com);
t_amb_light			amb_light_init(double f, t_rgb rgb);
t_cam				*cam_init(t_d3d o, t_vec p, double fov);
void				verbose_scene(void);
int					die(char *msg, unsigned char err);
int					minirt_exit(void *mlx);
void				scene_init(t_scn *sc);
int					scene_destroy(t_scn *sc);
void				light_init(t_d3d o, double f, t_rgb rgb);
void				sphere_init(t_d3d o, double d, t_rgb rgb);

# define FILE_ERROR		"Error loading file."
# define ERR_FILE		1
# define MLX_INIT_ERROR	"Error MLX init."
# define ERR_MLX_INIT	2
# define STRANGE_ERROR	"This is weird, you should not be here."
# define ERR_STRANGE	42

# define MSG_EXIT		"\n\nExit miniRT.\nThank you!\n\n"

#endif
