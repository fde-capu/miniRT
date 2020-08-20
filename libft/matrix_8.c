/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:26:47 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 15:27:04 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat	*matrix_new_mn(int m, int n)
{
	t_mat	*mnmn;

	mnmn = matrix_new();
	mnmn->m = m;
	mnmn->n = n;
	return (mnmn);
}
