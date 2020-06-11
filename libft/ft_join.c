/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:19:22 by fde-capu          #+#    #+#             */
/*   Updated: 2020/04/22 17:19:45 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char **split)
{
	char	*join;

	join = ft_strdup("");
	while (*split)
	{
		join = ft_strcatxl(join, *split);
		split++;
	}
	return (join);
}
