/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:04:45 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 14:53:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	debug(char *str, char *val, int *ival)
{
	if (!debug_pass())
		return ;
	return (debug_body(str, val ? val : 0, ival ? *ival : 0));
}

void	debug_body(char *str, char *val, int ival)
{
	char	*sval;

	if (!debug_pass())
		return ;
	sval = ft_itoa(ival);
	ft_putstr(str);
	ft_putstr(DEB_DIV);
	ft_putstr(val);
	ft_putstr(DEB_DIV);
	ft_putstr(sval);
	ft_putstr("\n");
	free(sval);
	return ;
}

void	debug_rgb(char *str, t_rgb rgb)
{
	char	*o;

	if (!debug_pass())
		return ;
	ft_putstr(str);
	ft_putstr(DEB_DIV);
	o = ft_rgbtoa(rgb);
	ft_putstr(o);
	ft_putstr("\n");
	free(o);
	return ;
}

void	debug_vector(char *str, t_vec *vec)
{
	char	*o;

	if (!debug_pass())
		return ;
	ft_putstr(str);
	ft_putstr(DEB_DIV);
	if (!vec)
	{
		ft_putstr(VOID_MSG);
		ft_putstr("\n");
		return ;
	}
	debug_matrix_single_line(vec);
	ft_putstr(DEB_DIV);
	o = ft_itoa((int)vec->m);
	ft_putstr(o);
	free(o);
	ft_putstr("\n");
	return ;
}

void	debug_matrix_single_line(t_mat *mat)
{
	t_dbl	*h;
	char	*o;

	o = ft_strnew();
	h = mat->i;
	while (h)
	{
		o = ft_strcatx(o, ft_dtoa(h->d));
		h = h->nx;
		if (h)
			o = ft_strcatxl(o, " ");
	}
	ft_putstr(o);
	free(o);
	return ;
}
