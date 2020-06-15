/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 19:07:30 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 11:04:51 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

int		keys_init(void)
{
	g_key = ft_calloc(sizeof(t_key), 1);
	return (1);
}

int		keys_destroy(void)
{
	t_key	*h;
	t_key	*n;

	h = g_key->nx;
	while (h)
	{
		n = h->nx ? h->nx : 0;
		free(h);
		h = n;
	}
	free(g_key);
	return (1);
}

t_key	*key(int id)
{
	t_key	*h;

	h = g_key->nx;
	while (h)
	{
		if (h->key_code == id)
			return (h);
		h = h->nx;
	}
	return (0);
}

t_key	*ft_key(char *key_code, int (*fun)(), void *arg)
{
	t_key	*kev;

	kev = key_interpret(key_code);
	kev->press = on_press;
	kev->release = on_release;
	kev->fun = fun;
	kev->arg = arg;
	keylist_add(kev);
	return (kev);
}

t_key	*key_interpret(char *kc)
{
	t_key	*kev;
	char	*h;

	kev = ft_calloc(sizeof(t_key), 1);
	h = kc;
	while (*h)
	{
		if (ft_islower(*h))
		{
			kev->key_code = *h;
		}
		h++;
	}
	return (kev);
}
