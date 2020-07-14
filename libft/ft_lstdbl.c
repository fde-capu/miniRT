/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 07:23:55 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 16:05:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstdbl_destroy(t_dbl *dbl)
{
	if (!dbl)
		return ;
	lstdbl_destroy(dbl->nx);
	free(dbl);
	return ;
}

t_dbl	*lstdbl_new(double val)
{
	t_dbl	*new;

	new = ft_calloc(sizeof(t_dbl), 1);
	new->d = val;
	return (new);
}

t_dbl	*lstdbl_last(t_dbl *h)
{
	if (!h)
		return (0);
	while (h->nx)
		h = h->nx;
	return (h);
}

t_dbl	*lstdbl_addlast(t_dbl *h, double d)
{
	if (!h)
	{
		h = lstdbl_new(d);
		return (h);
	}
	lstdbl_last(h)->nx = lstdbl_new(d);
	return (h);
}

void	lstdbl_mult_elem(t_dbl *ld, int e, int m)
{
	while (--e)
		ld = ld->nx;
	ld->d *= m;
	return ;
}
