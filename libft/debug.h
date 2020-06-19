/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 07:20:32 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/18 15:12:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEBUG_FLAG		1
# define VERBOSE_FLAG	1

# include "libft.h"

# define DEB_DIV			"\t :: \t"

# define DEBUG		debug
# define DEBSTR		debug_str
# define DEBSTR2	debug_str2
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
# define DEB2		debug_str_str
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
void	debug_str2(char *str, char *val, char *val2);
void	debug_str_only(char *str);
void	debug_double(char *str, double val);
void	debug_rgb(char *str, t_rgb rgb);
void	debug_vector(char *str, t_vec vec);
void	debug_str_add(char *str, void *add);
void	debug_str_str(char *str1, char *str2);

#endif
