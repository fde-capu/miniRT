/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:40:23 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 15:43:42 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MLX_H
# define LIBFT_MLX_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct	s_win {
	char		*title;
	int			height;
	int			width;
}				t_win;

typedef struct	s_mlx {
	void		*mlx;
	void		*win;
	t_win		w;
	t_i2d		cursor;
	t_rgb		color;
}				t_mlx;

t_mlx			*ft_mlx_init(int res_x, int res_y, char *win_title);
void			key_hook_toggle(t_mlx *mlx, int key);
void			hook_toggles(t_mlx *mlx, int ks, int ke);
int				ft_mlx_destroy(t_mlx *mlx);
void			ft_pix(t_mlx *mlx);
void			ft_mov(t_mlx *mlx, int x, int y);
void			ft_col(t_mlx *mlx, int color);

#endif
