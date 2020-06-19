/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_rt_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:38:21 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/17 17:23:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		valid_command(char **c)
{
	return (ft_strstr(c[0], VALID_COMMANDS) ? 1 : 0);
}

int		valid_arg_count(char **c)
{
	int	cc;

	cc = ft_strarrlen(c);
	if (((rt_c(c[0], "R") && cc != ARGS_R))
	|| ((rt_c(c[0], "A") && cc != ARGS_A))
	|| ((rt_c(c[0], "c") && cc != ARGS_C))
	|| ((rt_c(c[0], "l") && cc != ARGS_L))
	|| ((rt_c(c[0], "sp") && cc != ARGS_SP))
	|| ((rt_c(c[0], "pl") && cc != ARGS_PL))
	|| ((rt_c(c[0], "sq") && cc != ARGS_SQ))
	|| ((rt_c(c[0], "cy") && cc != ARGS_CY))
	|| ((rt_c(c[0], "tr") && cc != ARGS_TR)))
		return (0);
	return (1);
}

int		check_arg_types(char **c, int a[ARGS_MAX])
{
	int		i;
	char	*reg_rgb;

	reg_rgb = ft_strcat(REG_RGB1, REG_RGB2);
	i = 0;
	while (a[i])
	{
		if (((a[i] == ATP_UINT) && (!ft_check(c[i + 1], REG_UINT)))
		|| (((a[i] == ATP_0TO1) && (!ft_check(c[i + 1], REG_0TO1))))
		|| (((a[i] == ATP_RGB) && (!ft_check(c[i + 1], reg_rgb))))
		|| (((a[i] == ATP_COORD) && (!ft_check(c[i + 1], REG_COORD))))
		|| (((a[i] == ATP_UDBL) && (!ft_check(c[i + 1], REG_UDBL))))
		|| (((a[i] == ATP_NORMAL) && (!ft_check(c[i + 1], REG_NORMAL))))
		|| (((a[i] == ATP_0TO180DBL) && (!ft_check(c[i + 1], REG_0TO180DBL)))))
		{
			free(reg_rgb);
			return (0);
		}
		i++;
	}
	free(reg_rgb);
	return (1);
}

int		valid_arg_types(char **c)
{
	int		argt[ARGS_MAX];
	int		i;
	char	*tmp;
	char	*h;

	if (rt_c(c[0], "R"))
		tmp = ft_str(XARGS_R);
	if (rt_c(c[0], "A"))
		tmp = ft_str(XARGS_A);
	if (rt_c(c[0], "c"))
		tmp = ft_str(XARGS_C);
	if (rt_c(c[0], "l"))
		tmp = ft_str(XARGS_L);
	if (rt_c(c[0], "sp"))
		tmp = ft_str(XARGS_SP);
	if (rt_c(c[0], "pl"))
		tmp = ft_str(XARGS_PL);
	if (rt_c(c[0], "sq"))
		tmp = ft_str(XARGS_SQ);
	if (rt_c(c[0], "cy"))
		tmp = ft_str(XARGS_CY);
	if (rt_c(c[0], "tr"))
		tmp = ft_str(XARGS_TR);
	h = tmp;
	i = 0;
	while (*h)
	{
		argt[i] = *h - '0';
		i++;
		h++;
	}
	argt[i] = 0;
	free(tmp);
	return (check_arg_types(c, argt));
}

// must finish defines 0to180 and udbl
