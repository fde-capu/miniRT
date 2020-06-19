/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:31:57 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/19 09:25:15 by fde-capu         ###   ########.fr       */
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
	if (ft_chrinset(*mod, "+?*"))
		return (mod + 1);
	if (ft_chrinset(*mod, "{"))
		return (ft_inskip(mod) + 1);
	return (mod);
}

void	make_mod(int *mm, char *mod)
{
	mm_mod(&mm[0], 1, 1);
	if ((!mod) || (!*mod))
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

char	*ft_check(char *sh, char *rh)
{
	int		i;
	int		mm[2];
	char	*blk;
	char	*mod;
	char	**opt;
	int		(*chk_digit)(int);
	char	*(*chk_valid)(char *, char *);
	int		(*chk_set_v)(char r, char const *sset);
	int		(*chk_csame)(char a, char b);

	if ((*rh == '$') && (*sh))
		return (0);
	if (!*rh)
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
	if (*rh == '\\')
	{
		rh++;
		if (*rh == 'd')
		{
			chk_digit = &ft_isdigit;
			blk = rh;
			mod = *blk ? blk + 1 : 0;
			make_mod(&mm[0], mod);
			while (mm[0]-- > 0)
				if ((*sh) && (!chk_digit(*sh++)))
					return (0);
			while ((--mm[1]) && (chk_digit(*sh)))
				sh++;
			return (ft_check(sh, sk_mod(mod)));
		}
	}
	if (*rh == '(')
	{
		chk_valid = &ft_check;
		blk = ft_inside(rh);
		mod = *ft_inskip(rh) ? ft_inskip(rh) + 1 : 0;
		make_mod(&mm[0], mod);
		while (mm[0]-- > 0)
			if (!(sh = chk_valid(sh, blk)))
			{
				free(blk);
				return (0);
			}
		while ((--mm[1]) && (sh = chk_valid(sh, blk)))
			;
		free(blk);
		return (ft_check(sh, sk_mod(mod)));
	}
	if (*rh == '[')
	{
		chk_set_v = &ft_chrinset;
		blk = ft_inside(rh);
		mod = *ft_inskip(rh) ? ft_inskip(rh) + 1 : 0;
		make_mod(&mm[0], mod);
		while (mm[0]-- > 0)
			if ((*sh) && (!chk_set_v(*sh++, blk)))
			{
				free(blk);
				return (0);
			}
		while ((--mm[1]) && (chk_set_v(*sh, blk)))
			sh++;
		free(blk);
		return (ft_check(sh, sk_mod(mod)));
	}
	chk_csame = &ft_chrsame;
	blk = rh;
	mod = *blk ? blk + 1 : 0;
	make_mod(&mm[0], mod);
	while (mm[0]-- > 0)
		if ((*sh) && (!chk_csame(*sh++, *blk)))
			return (0);
	while ((--mm[1]) && (chk_csame(*sh, *blk)))
		sh++;
	return (ft_check(sh, sk_mod(mod)));
}
