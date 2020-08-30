/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:40:23 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/30 00:27:13 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTMLX_H
# define FTMLX_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define FTMLX_LIMIT_WIN_SIZE	1

t_hit	*collision_pix(t_mrt *mrt, t_ray *ray);
void	flip(t_mrt *mrt);
void	ft_col(t_mrt *mrt, unsigned int color);
char	*mrt_cursor(t_mrt *mrt, int x, int y);
t_mrt	*ft_mrt_init(void);
int		ft_mrt_init_img(t_mrt *mrt);
int		ft_mrt_init_win(t_mrt *mrt, char *win_title);
int		ft_mrt_destroy(void *mrt);
void	ft_pix(t_mrt *mrt, int x, int y, unsigned int color);
void	ft_pxi(t_mrt *mrt);
void	ft_key_mrt(t_mrt *mrt, \
			char *key_code, int (*fun)(void*), void *arg);
void	hook_keys(t_mrt *mrt, int ks, int ke);
t_vec	*pix_film(t_mrt *mrt, int i, int j);
t_vec	*pjt_pixtocam(t_mrt *mrt, int i, int j);
t_ray	*mrt_ray(t_mrt *mrt, int x, int y);

# define MSG_RENDERING	"\nRendering...\n"
# define MSG_DONE "Done.\n"

#endif
