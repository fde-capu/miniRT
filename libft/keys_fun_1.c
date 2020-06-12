/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_fun_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 23:23:53 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/11 23:23:55 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

int		on_press(int kc)
{
	key(kc)->st = KEY_ON;
	DEBINT2("pressed", kc, key(kc)->st);
	return (0);
}

int		on_release(int kc)
{
	key(kc)->st = KEY_OFF;
	DEBINT2("release", kc, key(kc)->st);
	return (0);
}
