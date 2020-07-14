/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_rt_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:50:35 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 16:30:46 by fde-capu         ###   ########.fr       */
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

void	rt_line_translate_2(t_scn *sc, char **c)
{
	if (rt_c(c[0], "l"))
		scn_add(TYPE_LHT, light_init(ft_atov(c[1]), ft_atod(c[2]),
			ft_atorgb(c[3])), sc);
	if (rt_c(c[0], "tr"))
		scn_add(TYPE_TRI, triangle_init(ft_atov(c[1]), ft_atov(c[2]),
			ft_atov(c[3]), ft_atorgb(c[4])), sc);
	if (rt_c(c[0], "sp"))
		scn_add(TYPE_PRM, sphere_init(ft_atov(c[1]), ft_atod(c[2]),
			ft_atorgb(c[3])), sc);
	if (rt_c(c[0], "pl"))
		scn_add(TYPE_PRM, plane_init(ft_atov(c[1]), ft_atov(c[2]),
			ft_atorgb(c[3])), sc);
	if (rt_c(c[0], "sq"))
		scn_add(TYPE_PRM, square_init(ft_atov(c[1]), ft_atov(c[2]),
			ft_atod(c[3]), ft_atorgb(c[4])), sc);
	if (rt_c(c[0], "cy"))
		scn_add(TYPE_PRM, cylinder_init(ft_atov(c[1]), ft_atov(c[2]),
			ft_atod(c[3]), ft_atod(c[4])), sc);
	if (rt_c(c[0], "cy"))
		sc->primitives->rgb = ft_atorgb(c[5]);
	if (((rt_c(c[0], "pl") || rt_c(c[0], "sq") || rt_c(c[0], "cy"))
		&& !is_normalized(sc->primitives->n))
		|| (rt_c(c[0], "tr") && !is_normalized(sc->faces->n)))
		die(0, NOTNORMAL_ERR, ERR_NOTNORMAL);
	return ;
}

void	rt_line_translate(t_scn *sc, char **c)
{
	if (rt_c(c[0], "R"))
	{
		if (sc->resolution)
			die(0, DOUBLE_E_ERROR, ERR_DOUBLE_E);
		sc->resolution = vector_build(2, (double)ft_atoi(c[1]), \
			(double)ft_atoi(c[2]));
		if (vector_get_element(sc->resolution, 1) <= 0 \
			|| vector_get_element(sc->resolution, 2) <= 0)
			die(0, INV_PARAM_ERR, ERR_INV_PARAM);
	}
	if (rt_c(c[0], "A"))
	{
		if (sc->ambient.f)
			die(0, DOUBLE_E_ERROR, ERR_DOUBLE_E);
		sc->ambient = amb_light_init(ft_atod(c[1]), ft_atorgb(c[2]));
		if (sc->ambient.f <= 0)
			die(0, INV_PARAM_ERR, ERR_INV_PARAM);
	}
	if (rt_c(c[0], "c"))
		scn_add(TYPE_CAM, cam_init(ft_atov(c[1]), ft_atov(c[2]),
			ft_atod(c[3])), sc);
	if ((rt_c(c[0], "c")) && (!is_normalized(sc->cam_list->p)))
		die(0, NOTNORMAL_ERR, ERR_NOTNORMAL);
	rt_line_translate_2(sc, c);
	return ;
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
		die(0, COM_ERROR, ERR_COM);
	}
	if ((!valid_arg_count(com)) || (!valid_arg_types(com)))
	{
		ft_strfree2d(com);
		die(0, ARGS_ERROR, ERR_ARGS);
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
