/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:47:37 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/02 07:20:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tl;

	if ((!lst) || (!new))
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tl = ft_lstlast(*lst);
	tl->nx = new;
	return ;
}
