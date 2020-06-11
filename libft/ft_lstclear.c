/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:47:51 by fde-capu          #+#    #+#             */
/*   Updated: 2020/04/15 11:39:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstclear(t_list **lst, void (*del)(void *))
{
	if ((!lst) || (!*lst) || (!*del))
		return ;
	if (!(*lst)->next)
	{
		del((*lst)->content);
		free(*lst);
		*lst = NULL;
		return ;
	}
	return ((void)ft_lstclear(&(*lst)->next, (*del)));
}

/*
** Maybe the code above is not completely tested.
*/
