/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_rt_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:38:21 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/13 13:06:46 by fde-capu         ###   ########.fr       */
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
	char	*reg_normal;

	reg_rgb = ft_strcat(REG_RGB1, REG_RGB2);
	reg_normal = ft_strcat(REG_NORMAL1, REG_NORMAL2);
	i = 0;
	while (a[i])
	{
		if ((a[i] == ATP_UINT && (!ft_check(c[i + 1], REG_UINT)))
		|| ((a[i] == ATP_0TO1 && (!ft_check(c[i + 1], REG_0TO1))))
		|| ((a[i] == ATP_RGB && (!ft_check(c[i + 1], reg_rgb))))
		|| ((a[i] == ATP_COORD && (!ft_check(c[i + 1], REG_COORD))))
		|| ((a[i] == ATP_UDBL && (!ft_check(c[i + 1], REG_UDBL))))
		|| ((a[i] == ATP_NORMAL && (!ft_check(c[i + 1], reg_normal))))
		|| ((a[i] == ATP_0TO180DBL && (!ft_check(c[i + 1], REG_0TO180DBL)))))
		{
			free(reg_rgb);
			free(reg_normal);
			return (0);
		}
		i++;
	}
	free(reg_rgb);
	free(reg_normal);
	return (1);
}

int		valid_arg_types(char **c)
{
	int		argt[ARGS_MAX];
	int		i;
	char	*tmp;
	char	*h;

	tmp = ft_str("");
	tmp = rt_c(c[0], "R") ? ft_x(tmp, ft_str(XARGS_R)) : tmp;
	tmp = rt_c(c[0], "A") ? ft_x(tmp, ft_str(XARGS_A)) : tmp;
	tmp = rt_c(c[0], "c") ? ft_x(tmp, ft_str(XARGS_C)) : tmp;
	tmp = rt_c(c[0], "l") ? ft_x(tmp, ft_str(XARGS_L)) : tmp;
	tmp = rt_c(c[0], "sp") ? ft_x(tmp, ft_str(XARGS_SP)) : tmp;
	tmp = rt_c(c[0], "pl") ? ft_x(tmp, ft_str(XARGS_PL)) : tmp;
	tmp = rt_c(c[0], "sq") ? ft_x(tmp, ft_str(XARGS_SQ)) : tmp;
	tmp = rt_c(c[0], "cy") ? ft_x(tmp, ft_str(XARGS_CY)) : tmp;
	tmp = rt_c(c[0], "tr") ? ft_x(tmp, ft_str(XARGS_TR)) : tmp;
	h = tmp;
	i = 0;
	while (*h)
		argt[i++] = *h++ - '0';
	argt[i] = 0;
	free(tmp);
	return (check_arg_types(c, argt));
}

void	die_if_random_error(t_mrt *mrt)
{
	if (!(mrt->scn->cam_list))
		die(0, CAMLESS_ERR, ERR_CAMLESS);
	return ;
}
