/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit8_fam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:45:03 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 08:07:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

u_int8_t	ft_bit8_get(u_int8_t *data, u_int8_t bit)
{
	return ((*data >> bit) & 1);
}

void		ft_bit8_set(u_int8_t *data, u_int8_t bit, u_int8_t val)
{
	if (val)
		*data |= (val << bit);
	else
		*data &= ~(1 << bit);
	return ;
}

void		ft_bit8_tog(u_int8_t *data, u_int8_t bit)
{
	ft_bit8_set(data, bit, ft_bit8_get(data, bit) ? 0 : 1);
	return ;
}

char		*ft_bit8_str(u_int8_t data)
{
	char	*str;

	str = ft_calloc(9, 1);
	str[0] = (char)ft_bit8_get(&data, 7 - 0) + '0';
	str[1] = (char)ft_bit8_get(&data, 7 - 1) + '0';
	str[2] = (char)ft_bit8_get(&data, 7 - 2) + '0';
	str[3] = (char)ft_bit8_get(&data, 7 - 3) + '0';
	str[4] = (char)ft_bit8_get(&data, 7 - 4) + '0';
	str[5] = (char)ft_bit8_get(&data, 7 - 5) + '0';
	str[6] = (char)ft_bit8_get(&data, 7 - 6) + '0';
	str[7] = (char)ft_bit8_get(&data, 7 - 7) + '0';
	return (str);
}
