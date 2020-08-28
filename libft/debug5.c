/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:51:51 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 14:19:44 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	debug_str_add(char *str, void *add)
{
	char	*o;

	if (!debug_pass())
		return ;
	debug_str(str, add);
	ft_putstr("\b");
	ft_putstr(DEB_DIV);
	o = ft_ptoa(&add);
	ft_putstr(o);
	ft_putstr("\n");
	free(o);
	return ;
}

void	debug_primitive(t_prm *h)
{
	char	*t;

	DEB(TIT_PRM);
	DEBSTR(S_TYPE, t = primitive_type_number(h->type));
	DEBVEC(S_ORIGIN, h->o);
	if (!ft_stridentical(t, TYPE_SP_NM))
		DEBVEC(S_NORMAL, h->n);
	free(t);
	DEBDBL(S_HEIGHT, h->h);
	DEBDBL(S_WIDTH, h->d);
	DEBRGB(S_COLOR, h->rgb);
	return ;
}

void	debug_ray(char *str, t_ray *ray)
{
	DEB(str);
	DEBVEC("a", ray->a);
	DEBVEC("b", ray->b);
	DEBVEC("d", ray->d);
	return ;
}
