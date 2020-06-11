/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removequotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:20:00 by fde-capu          #+#    #+#             */
/*   Updated: 2020/05/19 20:20:30 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rem_quotes(char *quoted, char quote)
{
	char	*unq;
	char	*ret;
	char	**split;
	char	**spl;

	split = ft_split(quoted, quote);
	spl = split;
	while (*spl)
	{
		if (*ft_lastchar(*spl) == '\\')
			*ft_lastchar(*spl) = quote;
		spl++;
	}
	unq = ft_join(split);
	spl = split;
	while (*split)
		free(*split++);
	free(spl);
	ret = ft_strdup(unq);
	free(unq);
	return (ret);
}

char	*ft_removequotes(char *quoted)
{
	char	*newq1;
	char	*newq2;

	newq1 = rem_quotes(quoted, '"');
	newq2 = rem_quotes(newq1, '\'');
	free(newq1);
	return (newq2);
}
