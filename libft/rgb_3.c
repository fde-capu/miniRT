/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:00:52 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 15:07:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rgb	color_normal(t_hit *hit)
{
	t_rgb	argb;
	t_vec	*tmp;

	tmp = vector_copy(hit->n);
	tmp = vectorx(tmp, vector_scalar_sum(tmp, 1.0));
	tmp = vectorx(tmp, vector_scalar_multiply(tmp, 0.5));
	tmp = vectorx(tmp, vector_scalar_multiply(tmp, 255.0));
	argb = ft_rgb(0,
		vector_get_element(tmp, 1),
		vector_get_element(tmp, 2),
		vector_get_element(tmp, 3));
	vector_destroy(tmp);
	return (argb);
}

t_rgb	ft_argb_multiply(t_rgb argb, double factor)
{
	t_rgb	ret;

	ret = ft_rgb(
		argb.a * factor,
		argb.r * factor,
		argb.g * factor,
		argb.b * factor);
	return (ret);
}

t_rgb	ft_argb_sum(t_rgb a, t_rgb b)
{
	t_rgb	ret;

	ret = ft_rgb(
		a.a + b.a,
		a.r + b.r,
		a.g + b.g,
		a.b + b.b);
	return (ret);
}

t_rgb	color_distance(t_hit *hit)
{
	t_rgb			argb;
	double			v;

	v = ft_trig(hit->t, 255.0, 500.0);
	argb = ft_rgb(0, v, v, v);
	return (argb);
}

t_rgb	color_blend(t_rgb a, t_rgb b, double factor)
{
	a = ft_argb_multiply(a, factor);
	b = ft_argb_multiply(b, 1 - factor);
	return (ft_argb_sum(a, b));
}
