/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:15:00 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 12:16:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vector_normalize(t_vec *mv)
{
	// to do
	(void)mv;
	return ;
}

int		is_normalized(t_vec *vec)
{
	return (vector_magnitude(vec) == 1 ? 1 : 0);
}
