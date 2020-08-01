/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:46:36 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/01 11:38:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*test_options(const char *sh, char *rh)
{
	int		i;
	char	**opt;
	char	*str;

	opt = ft_insplit(rh, '|');
	i = 0;
	while ((opt[1]) && (opt[i]))
	{
		if ((str = ft_check(sh, opt[i])))
		{
			ft_strfree2d(opt);
			return (str);
		}
		if (!opt[++i])
		{
			ft_strfree2d(opt);
			return (0);
		}
	}
	ft_strfree2d(opt);
	return (0);
}

static char	*test_function(int fun, int mm[2], char *sh, char *blk)
{
	if ((fun == FUN_SET) || (!rgx_fun_in(fun)))
	{
		while (mm[0]-- > 0)
			if ((*sh) && (!rgx_chk_function(fun, sh++, blk)))
			{
				rgx_maybe_free(blk, fun);
				return (0);
			}
		while ((--mm[1]) && (rgx_chk_function(fun, sh, blk)))
			sh++;
	}
	if (fun == FUN_PAR)
	{
		while (mm[0]-- > 0)
			if (!(sh = rgx_chk_function(fun, sh, blk)))
			{
				free(blk);
				return (0);
			}
		while ((--mm[1]) && (sh = rgx_chk_function(fun, sh, blk)))
			;
	}
	return (sh);
}

/*
** ft_check
** returns pointer to first unmatched char (or nothing)
*/

char		*ft_check(const char *sh, char *rh)
{
	int		mm[2];
	char	*blk;
	int		fun;

	if (rh && *rh == '$' && (*sh))
		return (0);
	if ((!rh) || (!*rh))
		return ((char *)sh);
	if (ft_insp_count(rh, '|') != 1)
		return (test_options(sh, rh));
	fun = rgx_function_n(rh);
	rh += ft_strbegins(rh, "\\") ? 1 : 0;
	blk = rgx_fun_in(fun) ? ft_inside(rh) : rh;
	rgx_set_rep(&mm[0], ft_inskip(rh));
	if (!(sh = test_function(fun, mm, (char *)sh, blk)))
		return (0);
	if (rgx_fun_in(fun))
		free(blk);
	rh = rgx_sk_mod(ft_inskip(rh));
	return (ft_check(sh, rh));
}
