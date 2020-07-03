/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:48:25 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/02 08:10:31 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_elem;
	t_list	*n_elem;

	f_elem = NULL;
	while (lst)
	{
		if ((n_elem = ft_lstnew(f(lst->content))))
		{
			ft_lstadd_back(&f_elem, n_elem);
			lst = lst->nx;
		}
		else
		{
			ft_lstclear(&lst, del);
			return (f_elem);
		}
	}
	return (f_elem);
}
