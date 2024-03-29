/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:38:51 by fde-capu          #+#    #+#             */
/*   Updated: 2020/09/01 23:14:04 by fde-capu         ###   ########.fr       */
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

# define WIN_TITLE		":: mrt : minirt : miniRT :: by fde-capu :: 42SP ::"
# define SAVE_FN		"minirt.bmp"

int						change_cam_up(void *mlx);
int						change_cam_down(void *mlx);
int						die(t_mrt *mrt, char *msg, unsigned char err);
void					die_if_random_error(t_mrt *mrt);
int						load_rt_file(char *fn, t_scn *sc);
int						minirt_exit(void *mrt);
void					mrt_win_binds(t_mrt *mrt);
void					render(t_mrt *mrt, int saving);
void					rt_line_interpret(char *ln, t_scn *sc);
int						rt_c(char *str, char *com);
void					rt_line_translate(t_scn *sc, char **c);
void					rt_line_translate_2(t_scn *sc, char **c);
void					*save_mrttobmp(t_mrt *mrt, char *fn);
int						valid_arg_count(char **c);
int						valid_arg_types(char **c);
int						valid_command(char **c);
void					write_mrtitobmp(t_mrt *mrt, int fp);
void					write_bmpheads(t_bmp *bmp, int fp);
void					scn_make_cylinder(t_scn *sc, char **c);
void					scn_make_square(t_scn *sc, char **c);
unsigned int			hit_and_bonus_color(t_mrt *mrt, t_hit *hit, \
							int x, int y);
int						scale_up(void *scn);
int						scale_down(void *scn);
int						translate_all_down(void *scn);
int						translate_all_up(void *scn);
int						rotate_all_obj(void *scn);
int						rotate_active_cam(void *scn);
int						translate_prm_tri_demo(void *scn, double factor);
int						translate_lht_cam_demo(void *scn, double factor);
t_vec					*demo_trans(t_vec *o, double factor);

# define ARGS_MAX		6

int						check_arg_types(char **c, int a[ARGS_MAX]);

# define SCALE_FACTOR	1.4
# define TRANSLATE_FACTOR	1.5
# define ROTATE_FACTOR	90

# define KEY_QUIT1		"{ESC}"
# define KEY_QUIT2		"q"
# define KEY_CAM_UP		"c"
# define KEY_CAM_DOWN	"{SHIFT}c"
# define KEY_SCALE_UP	"s"
# define KEY_SCALE_DOWN	"{SHIFT}s"
# define KEY_TRANS_UP	"t"
# define KEY_TRANS_DOWN	"{SHIFT}t"
# define KEY_ROT_UP		"r"
# define KEY_ROT_DOWN	"{SHIFT}r"

# define REQ_EXTENSION	".rt"

# define RT_SPLIT		" \t"
# define VALID_COMMANDS	"R A c l sp pl sq cy tr"

# define ERROR_STR_A	"Error\n["
# define ERROR_STR_B	"]: "
# define FILE_ERROR		"Error loading file."
# define ERR_FILE		1
# define MLX_INIT_ERROR	"Error MLX init."
# define ERR_MLX_INIT	2
# define ARGS_ERROR		"Wrong arguments."
# define ERR_ARGS		3
# define COM_ERROR		"Unknown command."
# define ERR_COM		4
# define IMG_ERROR		"Error image initialization."
# define ERR_IMG		5
# define WIN_ERROR		"Window creation error."
# define ERR_WIN		6
# define OPEN_W_ERROR	"Could not open file for writing."
# define ERR_OPEN_W		7
# define DOUBLE_E_ERROR	"Double entry."
# define ERR_DOUBLE_E	8
# define INV_PARAM_ERR	"Invalid parameter."
# define ERR_INV_PARAM	9
# define CAMLESS_ERR	"No camera found."
# define ERR_CAMLESS	10
# define NOTNORMAL_ERR	"Vector is not normalized."
# define ERR_NOTNORMAL	11
# define EXT_ERROR		"Bad file extension."
# define ERR_EXTENSION	12
# define STRANGE_ERROR	"This is weird, you should not be here."
# define ERR_STRANGE	42

# define MSG_EXIT		"\n\nExit miniRT.\nThank you!\n\n"
# define MSG_SAVED		"\nImage saved: "

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
# define REG_0TO1		"0*(1(\\.0*)?$|0*\\.?\\d*$)"
# define ATP_RGB		3
# define REG_RGB1		"(\\d{1,2},|1\\d{2},|2[01234]\\d,|25[012345],){2}"
# define REG_RGB2		"(\\d{1,2}$|1\\d{2}$|2[01234]\\d$|25[012345]$)"
# define ATP_COORD		4
# define REG_COORD		"-?\\d+\\.?\\d*,-?\\d+\\.?\\d*,-?\\d+\\.?\\d*$"
# define ATP_NORMAL		5
# define REG_NORMAL1	"((-?(0*\\.\\d*|0*\\.|0*1\\.0*|0*1\\.|0*1|0+)),){2}"
# define REG_NORMAL2	"((-?(0*\\.\\d*|0*\\.|0*1\\.0*|0*1\\.|0*1|0+))$)"
# define ATP_0TO180DBL	6
# define REG_0TO180DBL	"(0*1[012345678]\\d|0+|0*\\d{1,2})\\.?\\d*$"
# define ATP_UDBL		7
# define REG_UDBL		"\\d+\\.?\\d*$"

# define MSG_KEY_RELEASED	"Key released"
# define MSG_RX				"Resolution X"
# define MSG_RY				"Resolution Y"

#endif
