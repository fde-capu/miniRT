/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_h2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:52:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/19 15:01:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rgx_chk_function(int mode, char *sh, char *blk)
{
	if (mode == FUN_DIG)
		return (ft_isdigit(*sh) ? sh : 0);
	if (mode == FUN_PAR)
		return (ft_check(sh, blk));
	if (mode == FUN_SET)
		return (ft_chrinset(*sh, blk) ? sh : 0);
	if (mode == FUN_CHR)
		return (ft_chrsame(*sh, *blk) ? sh : 0);
	return (0);
}

int		rgx_fun_in(int fun)
{
	return (fun == FUN_PAR || fun == FUN_SET ? 1 : 0);
}

int		rgx_function_n(char *rh)
{
	if (ft_strbegins(rh, "\\d"))
		return (FUN_DIG);
	if (ft_strbegins(rh, "("))
		return (FUN_PAR);
	if (ft_strbegins(rh, "["))
		return (FUN_SET);
	return (FUN_CHR);
}

void	rgx_maybe_free(char *blk, int fun)
{
	if (rgx_fun_in(fun))
		free(blk);
	return ;
}
