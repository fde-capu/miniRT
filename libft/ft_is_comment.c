/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 08:25:41 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 10:57:17 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_comment(char *str)
{
	int		rv;

	rv = ft_chrinset(str, COMMENT_SET) ? 1 : 0;
	rv = str ? rv : 1;
	return (rv);
}
