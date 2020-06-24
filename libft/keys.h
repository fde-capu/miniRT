/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 18:46:07 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/23 16:34:04 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "../libft/libft.h"

typedef struct		s_key {
	int				key_code;
	char			state;
	struct s_key	*nx;
	int				(*press)(int);
	int				(*release)(int);
	int				(*fun)(void *);
	void			*arg;
	t_bol			shift;
	t_bol			ctrl;
	t_bol			alt;
	t_bol			key_up;
}					t_key;

# define KEY_OFF		0
# define KEY_ON			1
# define XPRESS			2
# define MPRESS			0
# define XRELEASE		3
# define MRELEASE		1
# define XCLOSE			17
# define MLEAVEWIN		5

t_key				*g_key;
int					keys_init(void);
int					keys_destroy(void);
t_key				*key(int id);
t_key				*ft_key(char *key_code, int (*fun)(void*), void *arg);
t_key				*key_interpret(char *kc);
void				keylist_add(t_key *new);
int					on_press(int kc);
int					on_release(int kc);

# define K_ESC 65307
# define K_SHIFT_L 65505
# define K_CTRL_L 65507
# define K_ALT_L 65513
# define K_SHIFT_R 65506
# define K_CTRL_R 65508
# define K_ALT_R 65027

#endif
