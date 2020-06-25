/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:27:28 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/25 14:38:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** char	*ft_convert_base (char *nbr, int b_fr, int b_to);
** or
** char	*ft_convert_base (int nbr, int b_fr, int b_to);
*/

char	*ft_convert_base(const void *bdata, ...)
{
	va_list	bd;
	char	*nbr;
	int		b_fr;
	int		b_to;
	char	*dec;

	va_start(bd, bdata);
	nbr = va_arg(bd, void *);
	b_fr = va_arg(bd, int);
	b_to = va_arg(bd, int);
	va_end(bd);
	if ((b_fr == 10) && (b_to == 10))
		return (nbr);
	if (b_fr == 10)
		return (ft_dtob(ft_atoi(nbr), b_to));
	if (b_to == 10)
		return (ft_itoa(ft_btod(nbr, b_to)));
	dec = ft_itoa(ft_btod(nbr, b_fr));
	dec = ft_dtob(ft_atoi(dec), b_to);
	return (dec);
}
