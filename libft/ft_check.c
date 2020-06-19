/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:31:57 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/19 13:20:38 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mm_mod(int *mm, int oblig, int optio)
{
	*mm = oblig;
	*(mm + 1) = optio;
	return ;
}

int		mm_manual(int pos, char *keys)
{
	char	*h;

	if (pos == 0)
		return (ft_atoi(keys + 1));
	if (pos == 1)
	{
		h = ft_findstr(keys, ',');
		return (h ? ft_atoi(h + 1) : mm_manual(0, keys));
	}
	return (1);
}

char	*sk_mod(char *mod)
{
	if ((!mod) || (!*mod))
		return (0);
	if (ft_chrinset(*mod, "+?*"))
		return (mod + 1);
	if (ft_chrinset(*mod, "{"))
		return (ft_inskip(mod));
	return (mod);
}

void	make_mod(int *mm, char *mod)
{
	mm_mod(&mm[0], 1, 1);
	if ((!mod) || (!(*mod)))
		return ;
	if (*mod == '+')
		mm_mod(&mm[0], 1, 0);
	if (*mod == '?')
		mm_mod(&mm[0], 0, 1);
	if (*mod == '*')
		mm_mod(&mm[0], 0, 0);
	if (*mod == '{')
		mm_mod(&mm[0], mm_manual(0, mod), mm_manual(1, mod));
	mm[1] -= (mm[0] - 1);
	mm[1] = mm[0] == 0 && mm[1] == 1 ? 0 : mm[1];
	return ;
}

char	*chk_function(int mode, char *sh, char *blk)
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

int		fun_in(int fun)
{
	return (fun == FUN_PAR || fun == FUN_SET ? 1 : 0);
}

char	*ft_check(char *sh, char *rh)
{
	int		i;
	int		mm[2];
	char	*blk;
	char	*mod;
	char	**opt;
	int		fun;

	DEB2(sh, rh);
	if (rh && *rh == '$' && (*sh))
		return (0);
	if ((!rh) || (!*rh))
		return (sh);
	opt = ft_insplit(rh, '|');
	i = 0;
	while ((opt[1]) && (opt[i]))
	{
		if ((blk = ft_check(sh, opt[i])))
		{
			ft_strfree2d(opt);
			return (blk);
		}
		if (!opt[++i])
		{
			ft_strfree2d(opt);
			return (0);
		}
	}
	ft_strfree2d(opt);
	fun = 0;
	if (ft_strbegins(rh, "\\d"))
		fun = FUN_DIG;
	if (*rh == '(')
		fun = FUN_PAR;
	if (*rh == '[')
		fun = FUN_SET;
	fun = fun ? fun : FUN_CHR;
	rh += ft_strbegins(rh, "\\") ? 1 : 0;
	if (fun_in(fun))
	{
		blk = ft_inside(rh);
		mod = ft_inskip(rh);
	}
	else
	{
		blk = rh;
		mod = *blk ? blk + 1 : 0;
	}
	make_mod(&mm[0], mod);
	if (!fun_in(fun))
	{
		while (mm[0]-- > 0)
			if ((*sh) && (!chk_function(fun, sh++, blk)))
				return (0);
		while ((--mm[1]) && (chk_function(fun, sh, blk)))
			sh++;
	}
	if (fun == FUN_PAR)
	{
		while (mm[0]-- > 0)
			if (!(sh = chk_function(FUN_PAR, sh, blk)))
			{
				free(blk);
				return (0);
			}
		while ((--mm[1]) && (sh = chk_function(FUN_PAR, sh, blk)))
			;
	}
	if (fun == FUN_SET)
	{
		while (mm[0]-- > 0)
			if ((*sh) && (!chk_function(FUN_SET, sh++, blk)))
			{
				free(blk);
				return (0);
			}
		while ((--mm[1]) && (chk_function(FUN_SET, sh, blk)))
			sh++;
	}
	if (fun_in(fun))
		free(blk);
	rh = sk_mod(mod);
	return (ft_check(sh, rh));
}
