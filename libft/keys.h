/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 18:46:07 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/11 14:41:36 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

typedef struct		s_key {
	int				id;
	char			st;
	struct s_key	*nx; //
	struct s_key	*pv; //
	int				(*on_press)(int keycode);
	int				(*on_release)(int keycode);
}					t_key;

# define KEYS_FIRST		0
# define KEYS_LAST		0xffff
# define KEY_OFF		0
# define KEY_ON			1
# define XPRESS			2
# define XRELEASE		3
# define MPRESS			0
# define MRELEASE		1

t_key				*g_key;
int					keys_init(void);
int					keys_destroy(void);
t_key				*key(int id);
int					*on_press(int kc);
int					*on_release(int kc);

#endif
