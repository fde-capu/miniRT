/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 02:03:11 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/30 02:03:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	primitive_transform(t_prm *prm, t_mat *trm)
{
	if (prm->o)
		vector_transform(&prm->o, trm);
	if (prm->n)
		vector_transform(&prm->n, trm);
	return ;
}
