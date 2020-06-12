/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 23:36:47 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/12 00:03:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

int	ev_close(t_mlx *mlx)
{
	ft_mlx_destroy(mlx);
	exit(0);	
}

int	test(t_mlx *mlx)
{
	ft_putstr("KEY!");
	return (1);
}
