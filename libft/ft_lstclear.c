/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:47:51 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/06 15:04:25 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstclear(t_list **lst, void (*del)(void *))
{
	if ((!lst) || (!*lst) || (!*del))
		return ;
	while (*lst)
	{
		del((*lst)->content);
		free(*lst);
		*lst = (*lst)->next;
	}
	*lst = NULL;
	return ;
}
