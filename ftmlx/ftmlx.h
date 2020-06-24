/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:40:23 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/24 15:58:56 by fde-capu         ###   ########.fr       */
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

typedef struct	s_img {
	int			height;
	int			width;
	char		*address;
	int			bpp;
	int			endian;
	int			line_l;
}				t_img;

typedef struct	s_mrt {
	void		*mlx;
	void		*win;
	void		*img;
	t_win		w;
	t_img		i;
	t_i2d		cursor;
	char		*icursor;
	t_rgb		color;
}				t_mrt;

t_mrt			*ft_mrt_init(void);
int				ft_mrt_init_img(t_mrt *mrt, int res_x, int res_y);
int				ft_mrt_init_win(t_mrt *mrt, int res_x, int res_y, char *win_title);
int				ft_mrt_destroy(void *mrt);
void			ft_pxw(t_mrt *mrt);
void			ft_pxi(t_mrt *mrt);
void			ft_mov(t_mrt *mrt, int x, int y);
void			ft_col(t_mrt *mrt, int color);
void			hook_keys(t_mrt *mrt, int ks, int ke);
void			ft_key_mrt
					(t_mrt *mrt, char *key_code, int (*fun)(void*), void *arg);

#endif
