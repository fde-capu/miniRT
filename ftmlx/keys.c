/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 19:07:30 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/11 09:50:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void	*on_press(int kc)
{
	key(kc)->st = KEY_ON;
	DEBINT2("pressed", kc, key(kc)->st);
	return (0);
}

void	*on_release(int kc)
{
	key(kc)->st = KEY_OFF;
	DEBINT2("release", kc, key(kc)->st);
	return (0);
}

int		keys_init(void)
{
	g_key = ft_calloc(sizeof(t_key) * (KEYS_LAST - KEYS_FIRST), 1);
	return (1);
}

int		keys_destroy(void)
{
	free(g_key_head);
	return (1);
}

t_key	key(int id)
{
	return (g_key[id]);
}
