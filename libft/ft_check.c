/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:31:57 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/17 16:22:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check(char *sh, char *rh)
{
	char	*t;
	char	**tt;
	int		i;
	char	*h;
	int		mm[2];

//	DEB2(sh, rh);
	if (!*rh)
		return (sh);
	if (*rh == '\\')
	{
		rh++;
		if (*rh == 'd')
		{
			if (*(rh + 1) == '+')
			{
				if (!ft_isdigit(*sh))
					return (0);
				while(ft_isdigit(*sh))
					sh++;
				return (ft_check(sh, rh + 2));
			}
			if (*(rh + 1) == '?')
			{
				if (ft_isdigit(*sh))
					sh++;
				return (ft_check(sh, rh + 2));
			}
			if (*(rh + 1) == '*')
			{
				while(ft_isdigit(*sh))
					sh++;
				return (ft_check(sh, rh + 2));
			}
			mm[0] = 1;
			mm[1] = 1;
			h = rh;
			if (*(rh + 1) == '{')
			{
				h = ft_inskip(rh + 1);
				t = ft_inside(rh + 1);
				tt = ft_split(t, ',');
				mm[0] = ft_atoi(tt[0]);
				mm[1] = ft_atoi(tt[1]);
//				DEBINT2("mm", mm[0], mm[1]);
				ft_strfree2d(tt);
				free(t);
			}
			i = 0;
			while (mm[0]--)
			{
				if (!ft_isdigit(*sh++))
					return (0);
				i++;
			}
			while (++i <= mm[1])
				if (ft_isdigit(*sh))
					sh++;
//			DEBSTR("=== in d ===", h);
			return (ft_check(sh, h + 1));
		}
	}
	if (*rh == '(')
	{
		h = ft_inskip(rh);
		tt = ft_insplit(rh, '|');
		i = 0;
		while (tt[i])
		{
//			DEB(tt[i]);
//			DEBINT("opt", i);
			if (ft_check(sh, tt[i]))
			{
				sh = ft_check(sh, tt[i]);
				ft_strfree2d(tt);
				h += ft_chrinset(*(h + 1), "?") ? 2 : 1;
//				DEB("<----------- OPT OK");
				return (h);
			}
			i++;
		}
		ft_strfree2d(tt);
		if (*(h + 1) == '?')
			return (ft_check(sh, h + 2));
		return (0);
	}
	if (*rh == '[')
	{
//		DEB("[");
		t = ft_inside(rh);
		h = ft_inskip(rh);
		if (ft_chrinset(*sh, t))
			sh++;
		free (t);
		return (ft_check(sh, h + 1));
	}
	if (*(rh + 1) == '*')
	{
		while (*rh == *sh)
			sh++;
		return (ft_check(sh, rh + 2));
	}
	if (*(rh + 1) == '?')
	{
		if (*sh == *rh)
			sh++;
		return (ft_check(sh, rh + 2));
	}
	mm[0] = 1;
	mm[1] = 1;
	h = rh;
	if (*(rh + 1) == '{')
	{	
		h = ft_inskip(rh + 1);
		t = ft_inside(rh + 1);
		tt = ft_split(t, ',');
		mm[0] = ft_atoi(tt[0]);
		mm[1] = ft_atoi(tt[1]);
		ft_strfree2d(tt);
		free(t);
	}
	i = 0;
	while (mm[0]--)
	{
		if (*rh != *sh++)
			return (0);
		i++;
	}
	while (++i <= mm[1])
		if (*rh == *sh)
			sh++;
//	DEBSTR("============", h);
	return (ft_check(sh, h + 1));
}
