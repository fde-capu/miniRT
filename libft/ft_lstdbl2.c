/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbl2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:24:46 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/14 11:51:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	lstdbl_pop(t_dbl *h)
{
	double	d;

	if (!h)
		return (0);
	if (!h->nx)
	{
		d = h->d;
		lstdbl_destroy(h);
		return (d);
	}
	while (h->nx->nx)
		h = h->nx;
	d = h->nx->d;
	lstdbl_destroy(h->nx);
	h->nx = 0;
	return (d);
}

t_dbl	*lstdbl_copy(t_dbl *h)
{
	t_dbl	*r;

	r = 0;
	while (h)
	{
		r = lstdbl_addlast(r, h->d);
		h = h->nx;
	}
	return (r);
}
