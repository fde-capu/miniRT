/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_rt_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:50:35 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/16 16:28:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rt_c(char *str, char *com)
{
	return (str && ft_stridentical(str, com) ? 1 : 0);
}

/*
** Cylinder gets 5 parameters from .rt file.
** Though norm does not allow 5 parameters functions!
** :/
*/

void	rt_line_translate(t_scn *sc, char **c)
{
	if (rt_c(c[0], "R"))
		sc->resolution = ft_i2d(ft_atoi(c[1]), ft_atoi(c[2]));
	if (rt_c(c[0], "A"))
		sc->ambient = amb_light_init(ft_atod(c[1]), ft_atorgb(c[2]));
	if (rt_c(c[0], "c"))
		sc->cam_active = cam_init(ft_atod3d(c[1]), ft_atovec(c[2]),
			ft_atod(c[3]));
	if (rt_c(c[0], "l"))
		light_init(ft_atod3d(c[1]), ft_atod(c[2]), ft_atorgb(c[3]));
	if (rt_c(c[0], "sp"))
		sphere_init(ft_atod3d(c[1]), ft_atod(c[2]), ft_atorgb(c[3]));
	if (rt_c(c[0], "pl"))
		plane_init(ft_atod3d(c[1]), ft_atovec(c[2]), ft_atorgb(c[3]));
	if (rt_c(c[0], "sq"))
		square_init(ft_atod3d(c[1]), ft_atovec(c[2]), ft_atod(c[3]),
			ft_atorgb(c[4]));
	if (rt_c(c[0], "cy"))
		cylinder_init(ft_atod3d(c[1]), ft_atovec(c[2]), ft_atod(c[3]),
			ft_atod(c[4]));
	if (rt_c(c[0], "cy"))
		sc->primitives->rgb = ft_atorgb(c[5]);
	if (rt_c(c[0], "tr"))
		triangle_init(ft_atod3d(c[1]), ft_atod3d(c[2]), ft_atod3d(c[3]),
			ft_atorgb(c[4]));
	return ;
}

int		valid_arg_count(char **c)
{
	int	cc;

	cc = ft_strarrlen(c);
	if (((rt_c(c[0], "R" ) && cc != ARGS_R))
	|| ((rt_c(c[0], "A" ) && cc != ARGS_A))
	|| ((rt_c(c[0], "c" ) && cc != ARGS_C))
	|| ((rt_c(c[0], "l" ) && cc != ARGS_L))
	|| ((rt_c(c[0], "sp") && cc != ARGS_SP))
	|| ((rt_c(c[0], "pl") && cc != ARGS_PL))
	|| ((rt_c(c[0], "sq") && cc != ARGS_SQ))
	|| ((rt_c(c[0], "cy") && cc != ARGS_CY))
	|| ((rt_c(c[0], "tr") && cc != ARGS_TR)))
		return (0);
	return (1);
}

int		valid_arg_types(char **c)
{
	return (1);
}

int		valid_command(char **c)
{
	return (ft_strstr(c[0], VALID_COMMANDS) ? 1 : 0);
}

void	rt_line_interpret(char *ln, t_scn *sc)
{
	char	**com;

	ft_putstr(ln);
	ln = ft_trim(ft_strdup(ln));
	if (ft_is_comment(ln))
	{
		free(ln);
		return ;
	}
	com = ft_split_set(ln, RT_SPLIT);
	free(ln);
	if (!valid_command(com))
	{
		ft_strfree2d(com);
		die(COM_ERROR, ERR_COM);
	}
	if ((!valid_arg_count(com)) || (!valid_arg_types(com)))
	{
		ft_strfree2d(com);
		die(ARGS_ERROR, ERR_ARGS);
	}
	rt_line_translate(sc, com);
	ft_strfree2d(com);
	return ;
}

int		load_rt_file(char *fn, t_scn *sc)
{
	int		fd;
	char	*buf;
	char	*ln;
	int		eof;

	fd = open(fn, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = ft_calloc(1 + 1, 1);
	eof = 0;
	ft_putstr_nl(fn);
	ln = ft_strnew();
	while (!eof)
	{
		ln = ft_x(ln, ft_strnew());
		while (!ft_lastchar_eq(ln, '\n') && !eof)
		{
			eof = read(fd, buf, 1) ? 0 : 1;
			ln = eof ? ln : ft_strcatxl(ln, buf);
		}
		rt_line_interpret(ln, sc);
	}
	free(ln);
	free(buf);
	return (1);
}
