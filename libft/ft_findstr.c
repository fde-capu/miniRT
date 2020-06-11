/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 20:25:22 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 14:13:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** returns the position in a string if found
**  or NULL if not found
** a.k.a. ft_strnchr(); ft_strchr();
*/

char	*ft_findstr(char *str, char c)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (str[i] == c)
		return (&str[i]);
	return (0);
}
