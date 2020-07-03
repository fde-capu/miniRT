/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 07:23:55 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/03 08:03:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdbl_destroy(t_dbl *dbl)
{
	if (!dbl)
		return ;
	ft_lstdbl_destroy(dbl->nx);
	free(dbl);
	return ;
}

t_dbl	*ft_lstdbl_new(double val)
{
	t_dbl	*new;

	new = ft_calloc(sizeof(t_dbl), 1);
	new->d = val;
	return (new);
}

t_dbl	*ft_lstdbl_last(t_dbl *h)
{
	while (h->nx)
		h = h->nx;
	return (h);
}

void	ft_lstdbl_addlast(t_dbl *h, double d)
{
	ft_lstdbl_last(h)->nx = ft_lstdbl_new(d);
	return ;
}
