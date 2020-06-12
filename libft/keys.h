/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 18:46:07 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/12 00:06:25 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "../libft/libft.h"

typedef struct		s_key {
	int				id;
	char			st;
	struct s_key	*nx; //
	struct s_key	*pv; //
	int				(*k_press)(int kc, int (fun)());
	int				(*k_release)(int kc, int (fun)());
}					t_key;

# define KEYS_FIRST		0
# define KEYS_LAST		0xffff
# define KEY_OFF		0
# define KEY_ON			1
# define XPRESS			2
# define MPRESS			0
# define XRELEASE		3
# define MRELEASE		1

t_key				*g_key;
int					keys_init(void);
int					keys_destroy(void);
t_key				*key(int id);
int					on_press(int kc, int (fun)());
int					on_release(int kc, int (fun)());

#endif
