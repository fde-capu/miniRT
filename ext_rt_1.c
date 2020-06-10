/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_rt_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:50:35 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 11:37:28 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rt_command(char *str, char *com)
{
	return (str && ft_stridentical(str, com) ? 1 : 0);
}

void	rt_line_interpret(char *ln, t_scn *sc)
{
	char	**com;

	ft_putstr(ln);
	ln = ft_trim(ft_strdup(ln));
	if(ft_is_comment(ln))
	{
		free(ln);
		return ;
	}
	com = ft_split(ln, ' ');
	free(ln);
	if (rt_command(com[0], "R"))
		sc->r = ft_i2d(ft_atoi(com[1]), ft_atoi(com[2]));
	if (rt_command(com[0], "A"))
		sc->a = amb_light_init(ft_atod(com[1]), ft_atorgb(com[2]));
	if (rt_command(com[0], "c"))
		sc->c = cam_init(ft_atod3d(com[1]), ft_atovec(com[2]), ft_atod(com[3]));
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
	DEBSTRADD("ln1", ln);
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
