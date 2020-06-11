/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:25:24 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 16:25:34 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int x;

	x = ft_strlen(s1) < ft_strlen(s2) ? \
		(int)ft_strlen(s1) : (int)ft_strlen(s2);
	return (ft_strncmp(s1, s2, x) ? 0 : 1);
}
