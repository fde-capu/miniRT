/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_fun_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 23:23:53 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 10:50:55 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

int		on_press(int kc)
{
	t_key	*k;

	k = key(kc);
	if (!k)
	{
		DEBINT("pressed (no map)", kc);
		return (0);
	}
	k->state = KEY_ON;
	DEBINT2("pressed", kc, k->state);
	g_key->shift = kc == K_SHIFT_L || kc == K_SHIFT_R ? KEY_ON : g_key->shift;
	g_key->ctrl = kc == K_CTRL_L || kc == K_CTRL_R ? KEY_ON : g_key->ctrl;
	g_key->alt = kc == K_ALT_L || kc == K_ALT_R ? KEY_ON : g_key->alt;
	k->fun(k->arg);
	return (1);
}

int		on_release(int kc)
{
	t_key	*k;

	k = key(kc);
	if (!k)
	{
		DEBINT("released (no map)", kc);
		return (0);
	}
	k->state = KEY_OFF;
	DEBINT2("release", kc, k->state);
	g_key->shift = kc == K_SHIFT_L || kc == K_SHIFT_R ? KEY_OFF : g_key->shift;
	g_key->ctrl = kc == K_CTRL_L || kc == K_CTRL_R ? KEY_OFF : g_key->ctrl;
	g_key->alt = kc == K_ALT_L || kc == K_ALT_R ? KEY_OFF : g_key->alt;
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
