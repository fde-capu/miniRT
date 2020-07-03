/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:40:23 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/03 11:19:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTMLX_H
# define FTMLX_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../ftmath/ftmath.h"

# define FTMLX_LIMIT_WIN_SIZE	1
# define ON_PIXEL_FLIP			0

void				flip(t_mrt *mrt);
t_mrt				*ft_mrt_init(void);
int					ft_mrt_init_img(t_mrt *mrt);
int					ft_mrt_init_win(t_mrt *mrt, char *win_title);
int					ft_mrt_destroy(void *mrt);
void				ft_pxi(t_mrt *mrt);
char				*ft_mov(t_mrt *mrt, int x, int y);
void				ft_col(t_mrt *mrt, unsigned int color);
void				ft_pix(t_mrt *mrt, int x, int y, unsigned int color);
void				hook_keys(t_mrt *mrt, int ks, int ke);
void				ft_key_mrt(t_mrt *mrt, \
						char *key_code, int (*fun)(void*), void *arg);

# define MSG_RENDERING	"\nRendering..."

#endif
