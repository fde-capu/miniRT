/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 12:22:09 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/24 12:27:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_args(int argc, char **argv, char *test)
{
	argc--;
	while (argc)
	{
		if (ft_stridentical(argv[argc], test))
			return (argv[argc + 1] ? argv[argc + 1] : argv[argc]);
		argc--;
	}
	return (0);
}
