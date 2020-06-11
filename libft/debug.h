/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 07:20:32 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/11 14:11:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEBUG_FLAG		1
# define VERBOSE_FLAG	1

# include "libft.h"

# define DEB_DIV			"\t :: \t"
# define MSG_KEY_RELEASED	"Key released"
# define MSG_RX				"Resolution X"
# define MSG_RY				"Resolution Y"

# define DEBUG		debug
# define DEBSTR		debug_str
# define DEBINT		debug_int
# define DEBINT2	debug_int2
# define VERBSTR	debug_str
# define VERBINT	debug_int
# define DEBDBL		debug_double
# define DEBRGB		debug_rgb
# define DEBVEC		debug_vector
# define DEBD3D		debug_vector
# define VERBOSE	verbose
# define DEB		debug_str_only
# define VERB		debug_str_only
# define DEBSTRADD	debug_str_add

int		g_debug;
int		g_verbose;

int		debug_pass(void);
void	debug(char *str, char *val, int *ival);
void	debug_body(char *str, char *val, int ival);
void	debug_int(char *str, int ival);
void	debug_int2(char *str, int val, int val2);
void	debug_str(char *str, char *val);
void	debug_str_only(char *str);
void	debug_double(char *str, double val);
void	debug_rgb(char *str, t_rgb rgb);
void	debug_vector(char *str, t_vec vec);
void	debug_str_add(char *str, void *add);

#endif
