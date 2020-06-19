/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:38:51 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/19 08:35:34 by fde-capu         ###   ########.fr       */
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

/*
** triangle normal does not come from file. :/
*/

typedef struct			s_triangle
{
	t_d3d				a;
	t_d3d				b;
	t_d3d				c;
	t_vec				n;
	t_rgb				rgb;
	struct s_triangle	*nx;
}						t_tr;

typedef struct			s_pimitive
{
	int					type;
	t_d3d				o;
	t_vec				n;
	double				h;
	double				d;
	t_rgb				rgb;
	struct s_pimitive	*nx;
}						t_prim;

typedef struct			s_camera
{
	t_d3d				o;
	t_vec				p;
	double				fov;
	struct s_camera		*nx;
}						t_cam;

typedef struct			s_amb_light
{
	double				f;
	t_rgb				rgb;
}						t_amb_light;

typedef struct			s_light
{
	t_d3d				o;
	double				f;
	t_rgb				rgb;
	struct s_light		*nx;
}						t_light;

typedef struct			s_scene
{
	t_i2d				resolution;
	t_amb_light			ambient;
	t_cam				*cam_active;
	t_cam				*cam_list;
	t_light				*lights;
	t_prim				*primitives;
	t_tr				*faces;
}						t_scn;

t_scn					*g_scn;
t_mlx					*g_mlx;

int						load_rt_file(char *fn, t_scn *sc);
void					rt_line_interpret(char *ln, t_scn *sc);
int						rt_c(char *str, char *com);
t_amb_light				amb_light_init(double f, t_rgb rgb);
t_cam					*cam_init(t_d3d o, t_vec p, double fov);
void					verbose_scene(void);
int						die(char *msg, unsigned char err);
int						minirt_exit(void *mlx);
void					scene_init(t_scn *sc);
int						scene_destroy(t_scn *sc);
void					light_init(t_d3d o, double f, t_rgb rgb);
void					sphere_init(t_d3d o, double d, t_rgb rgb);
void					plane_init(t_d3d o, t_vec n, t_rgb rgb);
void					square_init(t_d3d o, t_vec n, double h, t_rgb rgb);
void					cylinder_init(t_d3d o, t_vec n, double h, double d);
void					triangle_init(t_d3d a, t_d3d b, t_d3d c, t_rgb rgb);
void					scn_free_list_light(t_light *lst);
void					scn_free_list_cam(t_cam *lst);
void					scn_free_list_prim(t_prim *lst);
void					scn_free_list_tr(t_tr *lst);
void					rt_line_translate(t_scn *sc, char **c);
int						valid_arg_count(char **c);
int						valid_arg_types(char **c);
int						valid_command(char **c);

# define ARGS_MAX		6

int						check_arg_types(char **c, int a[ARGS_MAX]);

# define RT_SPLIT		" \t"
# define VALID_COMMANDS	"R A c l sp pl sq cy tr"

# define FILE_ERROR		"Error loading file."
# define ERR_FILE		1
# define MLX_INIT_ERROR	"Error MLX init."
# define ERR_MLX_INIT	2
# define ARGS_ERROR		"Wrong arguments."
# define ERR_ARGS		3
# define COM_ERROR		"Unknown command."
# define ERR_COM		4
# define STRANGE_ERROR	"This is weird, you should not be here."
# define ERR_STRANGE	42

# define MSG_EXIT		"\n\nExit miniRT.\nThank you!\n\n"

# define TYPE_SP_NM		"Sphere"
# define TYPE_SP		1
# define TYPE_PL_NM		"Plane"
# define TYPE_PL		2
# define TYPE_SQ_NM		"Square"
# define TYPE_SQ		3
# define TYPE_CY_NM		"Cylinder"
# define TYPE_CY		4

# define ARGS_R			3
# define ARGS_A			3
# define ARGS_C			4
# define ARGS_L			4
# define ARGS_SP		4
# define ARGS_PL		4
# define ARGS_SQ		5
# define ARGS_CY		6
# define ARGS_TR		5

# define XARGS_R		"11"
# define XARGS_A		"23"
# define XARGS_C		"456"
# define XARGS_L		"423"
# define XARGS_SP		"473"
# define XARGS_PL		"453"
# define XARGS_SQ		"4573"
# define XARGS_CY		"45773"
# define XARGS_TR		"4443"

# define ATP_UINT		1
# define REG_UINT		"\\d+$"
# define ATP_0TO1		2
# define REG_0TO1		"0*(1(\\.0?)?$|0*\\.?\\d*$)"
# define ATP_RGB		3
# define REG_RGB1		"(\\d{1,2},|1\\d{2},|2[01234]\\d,|25[012345],){2}"
# define REG_RGB2		"(\\d{1,2}$|1\\d{2}$|2[01234]\\d$|25[012345]$)"
# define ATP_COORD		4
# define REG_COORD		"-?\\d+\\.?\\d*,-?\\d+\\.?\\d*,-?\\d+\\.?\\d*$"
# define ATP_NORMAL		5
# define REG_NORMAL		"(-?(1\\.0|0\\.?\\d*),){2}-?(1\\.0$|0\\.?\\d*$)"
# define ATP_0TO180DBL	6
# define REG_0TO180DBL	"(0*1[012345678]\\d|0+|0*\\d{1,2})\\.?\\d*$"
# define ATP_UDBL		7
# define REG_UDBL		"\\d+\\.?\\d*$"

# define MSG_KEY_RELEASED	"Key released"
# define MSG_RX				"Resolution X"
# define MSG_RY				"Resolution Y"

#endif
