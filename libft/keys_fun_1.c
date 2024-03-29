/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_fun_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 23:23:53 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/29 09:51:30 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

int		set_mods(int kc, int onoff)
{
	g_key->shift = kc == K_SHIFT_L || kc == K_SHIFT_R ? onoff : g_key->shift;
	g_key->ctrl = kc == K_CTRL_L || kc == K_CTRL_R ? onoff : g_key->ctrl;
	g_key->alt = kc == K_ALT_L || kc == K_ALT_R ? onoff : g_key->alt;
	SUBDEBINT("mod", kc, SUBDEB_KEYS);
	return (kc == K_SHIFT_L || kc == K_SHIFT_R || kc == K_CTRL_L
		|| kc == K_CTRL_R || kc == K_CTRL_R || kc == K_ALT_L
		|| kc == K_ALT_R ? 1 : 0);
}

int		on_press(int kc)
{
	t_key	*k;

	if (set_mods(kc, KEY_ON))
		return (0);
	k = key(kc);
	if (!k)
	{
		SUBDEBINT("pressed (no map)", kc, SUBDEB_KEYS);
		return (0);
	}
	SUBDEBINT2("pressed", kc, k->state, SUBDEB_KEYS);
	k->state = KEY_ON;
	if (!(k->key_up))
		k->fun(k->arg);
	return (1);
}

int		on_release(int kc)
{
	t_key	*k;

	if (set_mods(kc, KEY_OFF))
		return (0);
	k = key(kc);
	if (!k)
	{
		SUBDEBINT("released (no map)", kc, SUBDEB_KEYS);
		return (0);
	}
	k->state = KEY_OFF;
	SUBDEBINT2("release", kc, k->state, SUBDEB_KEYS);
	if (k->key_up)
		k->fun(k->arg);
	return (1);
}

void	keylist_add(t_key *new)
{
	new->nx = g_key->nx;
	g_key->nx = new;
	return ;
}
