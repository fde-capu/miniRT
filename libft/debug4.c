/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:45:23 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/12 08:30:23 by fde-capu         ###   ########.fr       */
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
	if (!debug_pass())
		return ;
	ft_putstr(str);
	if (!mat)
	{
		ft_putstr(VOID_MSG);
		ft_putstr("\n");
		return ;
	}
	debug_int2("", mat->m, mat->n);
	debug_matrix_2(mat);
	ft_putstr("\n");
	return ;
}

void	debug_matrix_2(t_mat *mat)
{
	int		i;
	int		j;
	char	*o;

	o = ft_strnew();
	i = 1;
	while (i <= mat->m)
	{
		ft_putstr(DEB_DIV);
		j = 1;
		while (j <= mat->n)
		{
			o = ft_x(o, ft_dtoa(matrix_get_element(mat, i, j)));
			ft_putstr(o);
			ft_putstr(DEB_DIV);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
	free(o);
	return ;
}

void	debug_matrix_of_vectors(char *str, t_mvec *mat)
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

void	debug_double2(char *str, double val, double val2)
{
	char	*o;

	if (!debug_pass())
		return ;
	ft_putstr(str);
	ft_putstr(DEB_DIV);
	o = ft_dtoa(val);
	ft_putstr(o);
	ft_putstr(DEB_DIV);
	o = ft_x(o, ft_dtoa(val2));
	ft_putstr(o);
	ft_putstr("\n");
	free(o);
	return ;
}
