/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:45:23 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/02 12:52:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	debug_t_dbl(char *str, t_dbl *dbl)
{
	DEBDBL(str, dbl->d);
	return ;
}

void	debug_matrix(char *str, t_mat *mat)
{
	char	*o;

	if (!debug_pass())
		return ;
	ft_putstr(str);
	ft_putstr(DEB_DIV);
	o = ft_itoa(mat->m);
	ft_putstr(o);
	ft_putstr(DEB_DIV);
	o = ft_x(o, ft_itoa(mat->n));
	ft_putstr(o);
	ft_putstr("\n");
	free(o);
	return ;
}
