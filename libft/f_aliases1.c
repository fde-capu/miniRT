/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_aliases1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:16:15 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 11:30:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, char c)
{
	return (ft_findstr(str, c));
}

char	*ft_strnchr(char *str, char c)
{
	return (ft_findstr(str, c));
}
