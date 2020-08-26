/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_rt_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:50:35 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/26 02:01:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rt_c(char *str, char *com)
{
	return (str && ft_stridentical(str, com) ? 1 : 0);
}

void	scn_make_cylinder(t_scn *sc, char **c)
{
	t_vec	*origin_b;
	t_vec	*normal;
	double	diameter;
	double	height;
	t_rgb	rgb;
	t_vec	*origin_t;

	origin_b = ft_atov(c[1]);
	normal = ft_atov(c[2]);
	diameter = ft_atod(c[3]);
	height = ft_atod(c[4]);
	rgb = ft_atorgb(c[5]);
	scn_add(TYPE_PRM, cylinder_init(origin_b, normal, diameter, height), sc);
	sc->primitives->rgb = rgb;
	if (BONUS)
	{
		origin_t = vector_scalar_multiply(normal, height);
		origin_t = vectorx(origin_t, vector_sum(origin_t, origin_b));
		scn_add(TYPE_PRM, disc_init(origin_t, vector_copy(normal), diameter, rgb), sc);
		normal = vector_scalar_multiply(normal, -1.0);
		scn_add(TYPE_PRM, disc_init(vector_copy(origin_b), normal, diameter, rgb), sc);
	}
	return ;
}

double	hit_cylinder(t_ray *ray3d, t_prm *cylinder)
{
	double	t;
	t_prm	*cyl;
	t_ray	*ray;
	double	dx;
	double	dy;
	double	x0;
	double	y0;
	double	a;
	double	b;
	double	c;

	ray = ray_copy(ray3d);
	cyl = cylinder_init(vector_copy(cylinder->o), vector_copy(cylinder->n), cylinder->h, cylinder->d);
	primitive_zzz_position(cyl, ray);
	dx = vector_get_element(ray->d, 1);
	dy = vector_get_element(ray->d, 2);
	x0 = vector_get_element(ray->a, 1);
	y0 = vector_get_element(ray->a, 2);
	a = ((dx * dx) + (dy * dy));
	b = ((x0 * dx) + (y0 * dy)) * 2;
	c = ((x0 * x0) + (y0 * y0)) - ((cyl->h / 2) * (cyl->h / 2));
	t = quadratic_minor(a, b, c);
	if (!inside_cylinder_bondaries(ray3d, t, cylinder))
	{
		if (!BONUS)
		{
			t = quadratic_major(a, b, c);
			if (!inside_cylinder_bondaries(ray3d, t, cylinder))
				t = 0.0;
		}
		else
			t = 0.0;
	}
	ray_destroy(ray);
	primitive_destroy(cyl);
	return (t);
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
		scn_make_cylinder(sc, c);
	if ((rt_c(c[0], "pl") || rt_c(c[0], "sq") || rt_c(c[0], "cy"))
		&& !is_normalized(sc->primitives->n))
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
