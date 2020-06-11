/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 07:39:21 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/09 07:52:29 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcat(void *m1, void *m2, int s1, int s2)
{
	void	*nm;
	char	*w;

	nm = malloc(s1 + s2);
	w = nm;
	ft_memcpy(w, m1, s1);
	w = nm + s1;
	ft_memcpy(w, m2, s2);
	return (nm);
}

void			*ft_memcatx(void *m1, void *m2, int s1, int s2)
{
	void	*nm;
	char	*w;

	nm = malloc(s1 + s2);
	w = nm;
	ft_memcpy(w, m1, s1);
	w = nm + s1;
	ft_memcpy(w, m2, s2);
	free(m1);
	free(m2);
	return (nm);
}

void			*ft_memcatxl(void *m1, void *m2, int s1, int s2)
{
	void	*nm;
	char	*w;

	nm = malloc(s1 + s2);
	w = nm;
	ft_memcpy(w, m1, s1);
	w = nm + s1;
	ft_memcpy(w, m2, s2);
	free(m1);
	return (nm);
}

void			*ft_memcatxr(void *m1, void *m2, int s1, int s2)
{
	void	*nm;
	char	*w;

	nm = malloc(s1 + s2);
	w = nm;
	ft_memcpy(w, m1, s1);
	w = nm + s1;
	ft_memcpy(w, m2, s2);
	free(m2);
	return (nm);
}
