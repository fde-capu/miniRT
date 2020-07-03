/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:38:51 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/02 11:55:28 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "ftmath/ftmath.h"
# include "ftmlx/ftmlx.h"
# include "minilibx-linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define WIN_TITLE	":: mrt : minirt : miniRT :: by fde-capu :: 42SP ::"
# define SAVE_FN	"minirt.bmp"

int						load_rt_file(char *fn, t_scn *sc);
void					rt_line_interpret(char *ln, t_scn *sc);
int						rt_c(char *str, char *com);
int						die(t_mrt *mrt, char *msg, unsigned char err);
int						minirt_exit(void *mrt);
void					rt_line_translate(t_scn *sc, char **c);
void					rt_line_translate_2(t_scn *sc, char **c);
int						valid_arg_count(char **c);
int						valid_arg_types(char **c);
int						valid_command(char **c);
int						change_cam_up(void *mlx);
int						change_cam_down(void *mlx);
void					write_mrtitobmp(t_mrt *mrt, int fp);
void					write_bmpheads(t_bmp *bmp, int fp);
void					*save_mrttobmp(t_mrt *mrt, char *fn);
void					mrt_win_binds(t_mrt *mrt);
void					render(t_mrt *mrt);
void					flip(t_mrt *mrt);

# define ARGS_MAX		6

int						check_arg_types(char **c, int a[ARGS_MAX]);

# define KEY_QUIT1		"{ESC}"
# define KEY_QUIT2		"q"
# define KEY_CAM_UP		"c"
# define KEY_CAM_DOWN	"{SHIFT}c"

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
# define STRANGE_ERROR	"This is weird, you should not be here."
# define ERR_STRANGE	42

# define MSG_EXIT		"\n\nExit miniRT.\nThank you!\n\n"
# define MSG_SAVED		"\nImage saved: "
# define MSG_RENDERING	"\nRendering..."

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
# define M11			"-?(0*\\.\\d*|0*1(\\.0*)?|0+)"
# define REG_NORMAL		"(("M11"),){2}("M11")$"
# define ATP_0TO180DBL	6
# define REG_0TO180DBL	"(0*1[012345678]\\d|0+|0*\\d{1,2})\\.?\\d*$"
# define ATP_UDBL		7
# define REG_UDBL		"\\d+\\.?\\d*$"

# define MSG_KEY_RELEASED	"Key released"
# define MSG_RX				"Resolution X"
# define MSG_RY				"Resolution Y"

#endif
