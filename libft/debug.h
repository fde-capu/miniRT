/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 07:20:32 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/15 12:58:56 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEBUG_FLAG		1
# define VERBOSE_FLAG	1
# define SUBDEB_KEYS	0

# include "libft.h"

# define DEB_DIV		"\t :: \t"
# define VOID_MSG		"(void)"
# define TIT_CAM		"\nCamera"
# define TIT_LHT		"\nLight"
# define TIT_PRM		"\nPrimitive"
# define TIT_TRI		"\nTriangle/Face"
# define TIT_SCN		"\nScene"
# define TIT_CAM_ACT	"Active Camera:"
# define S_ORIGIN		"      origin"
# define S_FORCE		"       force"
# define S_COLOR		"  color argb"
# define S_NORMAL		"      normal"
# define S_HEIGHT		"      height"
# define S_WIDTH		"       width"
# define S_DIAMETER		"    diameter"
# define S_VERTEX		"      vertex"
# define S_RESOLUTION	"  resolution"
# define S_FOV			"         fov"
# define S_TYPE			"        type"

# define DEBUG		debug
# define DEBSTR		debug_str
# define DEBSTR2	debug_str2
# define DEBINT		debug_int
# define DEBINT2	debug_int2
# define SUBDEBINT	subdebug_int
# define SUBDEBINT2	subdebug_int2
# define VERBSTR	debug_str
# define VERBINT	debug_int
# define DEBDBL		debug_double
# define DEBTDBL	debug_t_dbl
# define DEBRGB		debug_rgb
# define DEBVEC		debug_vector
# define VERBOSE	verbose
# define DEB		debug_str_only
# define DEB2		debug_str_str
# define VERB		debug_str_only
# define DEBSTRADD	debug_str_add
# define DEBMAT		debug_matrix
# define DEBMATVEC	debug_matrix_of_vectors

int		debug_pass(void);
void	debug(char *str, char *val, int *ival);
void	debug_body(char *str, char *val, int ival);
void	debug_int(char *str, int ival);
void	debug_int2(char *str, int val, int val2);
void	subdebug_int(char *str, int ival, int subdeb);
void	subdebug_int2(char *str, int val, int val2, int subdeb);
void	debug_str(char *str, char *val);
void	debug_str2(char *str, char *val, char *val2);
void	debug_str_only(char *str);
void	debug_double(char *str, double val);
void	debug_rgb(char *str, t_rgb rgb);
void	debug_vector(char *str, t_vec *vec);
void	debug_str_add(char *str, void *add);
void	debug_str_str(char *str1, char *str2);
void	debug_t_dbl(char *str, t_dbl *dbl);
void	debug_matrix(char *str, t_mat *mat);
void	debug_matrix_of_vectors(char *str, t_mvec *mat);
void	debug_matrix_2(t_mat *mat);

#endif
