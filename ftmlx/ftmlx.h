/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:40:23 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/24 13:38:57 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTMLX_H
# define FTMLX_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define FTMLX_LIMIT_WIN_SIZE	1

typedef struct	s_win {
	char		*title;
	int			height;
	int			width;
}				t_win;

typedef struct	s_mrt {
	void		*mlx;
	void		*win;
	t_win		w;
	t_i2d		cursor;
	t_rgb		color;
}				t_mrt;

t_mrt			*ft_mrt_init(int res_x, int res_y, char *win_title);
int				ft_mrt_destroy(void *mlx);
void			ft_pix(t_mrt *mlx);
void			ft_mov(t_mrt *mlx, int x, int y);
void			ft_col(t_mrt *mlx, int color);
void			hook_keys(t_mrt *mlx, int ks, int ke);
void			ft_key_mlx
					(t_mrt *mlx, char *key_code, int (*fun)(void*), void *arg);

#endif
