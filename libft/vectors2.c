/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 08:04:00 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/03 17:57:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mat_destroy(t_mat *mat)
{
	if (!mat)
		return ;
	ft_lstdbl_destroy(mat->i);
	free(mat);
	return ;
}

void	ft_mvec_destroy(t_mvec *mat)
{
	t_vec	*h;
	t_vec	*n;

	if (!mat)
		return ;
	h = mat->i;
	n = h->nx;
	while (n)
	{
		ft_vec_destroy(h);
		h = n;
		n = n->nx;
	}
	ft_vec_destroy(h);
	return ;
}

t_vec	*ft_vecx(t_vec *old, t_vec *new)
{
	ft_vec_destroy(old);
	return (new);
}

void	ft_vm_add(t_mvec *mv, int i, int j, t_vec *vec)
{
	t_vec	*h;

	h = ft_vm(mv, i, j);
	if (h->pv)
	{
		vec->pv = h->pv;
		vec->nx = h->nx;
		vec->pv->nx = vec;
		ft_vec_destroy(h);
	}
	else
	{
		vec->pv = 0;
		vec->nx = mv->i->nx;
		mv->i = ft_vecx(mv->i, vec);
	}
	return ;
}
