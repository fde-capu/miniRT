/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:49:58 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/13 12:02:18 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ftmath.h"

t_matlst	*matrix_list_init(void)
{
	t_matlst	*ml;
	
	ml = ft_calloc(sizeof(t_matlst), 1);
	return (ml);
}
void	math_init(void)
{
	g_matops = matrix_list_init();
	return ;
}
