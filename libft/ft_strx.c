/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 13:59:19 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 10:52:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strx
** Usage: new_str = ft_strx(new_val, str_to_free);
** Usually: str = (new_str, str);
*/

char	*ft_strx(char *s1, char *s2)
{
	return (ft_x(s2, ft_strdup(s1)));
}
