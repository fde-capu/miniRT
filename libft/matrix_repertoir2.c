/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_repertoir2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:54:14 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/15 12:55:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat	*matrix_diagonal_is(t_vec *dvec)
{
	t_mat	*mid;
	int		i;
	int		sts;
	int		sp1;
	int		x;

	x = 1;
	mid = ft_calloc(sizeof(t_mat), 1);
	sts = dvec->m * dvec->m;
	sp1 = dvec->m + 1;
	i = 1;
	while (i <= sts)
	{
		if (i % sp1 == 1)
			mid->i = lstdbl_addlast(mid->i, vector_get_element(dvec, x++));
		else
			mid->i = lstdbl_addlast(mid->i, 0);
		i++;
	}
	mid->m = dvec->m;
	mid->n = dvec->m;
	return (mid);
}

void	vector_append_val(t_vec *vec, double val)
{
	lstdbl_addlast(vec->i, val);
	vec->m++;
	return ;
}
