/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_file_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:01:42 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/30 18:01:57 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		bad_file_extension(char *fn, char *required_extension)
{
	char	*ext;

	if (ft_strlen(required_extension) > ft_strlen(fn))
		return (1);
	ext = fn + (ft_strlen(fn) - ft_strlen(required_extension));
	if (ft_stridentical(ext, required_extension))
		return (0);
	return (1);
}
