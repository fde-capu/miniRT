/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 07:55:47 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/02 07:59:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** math_simple should not use <math.h>
*/

int	ft_ceil(double d)
{
	int	comp;

	comp = (int)d;
	if ((double)comp == (double)d)
		return (comp);
	else
		return (comp + 1);
}
