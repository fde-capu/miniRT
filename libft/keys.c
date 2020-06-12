/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 19:07:30 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/12 00:02:30 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void	key_init(int k)
{
	if (k < KEYS_LAST)
	{
		key(k)->k_press = on_press;
		key(k)->k_release = on_release;
		key_init(k + 1);
	}
	return ;
}

int		keys_init(void)
{
	g_key = ft_calloc(sizeof(t_key) * (KEYS_LAST - KEYS_FIRST), 1);
	key_init(KEYS_FIRST);
	return (1);
}

int		keys_destroy(void)
{
	free(g_key);
	return (1);
}

t_key	*key(int id)
{
	return (&g_key[id]);
}
