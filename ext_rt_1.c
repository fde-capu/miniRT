/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_rt_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:50:35 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 10:54:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_line_interpret(char *ln, t_scn *sc)
{
	char	**com;

	ft_putstr(ln);
	if(ft_is_comment(ln))
		return ;
	ln = ft_strtrim(ln, TRIM_SET);
	com = ft_split(ln, ' ');
	free(ln);
	if (com[0] && ft_stridentical(com[0], "R"))
	{
		sc->r.x = ft_atoi(com[1]);
		sc->r.y = ft_atoi(com[2]);
	}
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
		ln = ft_strx(ft_strnew(), ln);
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
