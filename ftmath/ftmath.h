/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:04:58 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/21 16:37:56 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTMATH_H
# define FTMATH_H

# include "../libft/libft.h"
# include <math.h>

/*
** CGs are here on purpose.
** triangle normal does not come from mini.rt :/
*/

double		hipo(double c1, double c2);
t_alt		amb_light_init(double f, t_rgb rgb);
t_cam		*cam_init(t_vec *o, t_vec *p, double fov);
t_scn		*scene_init(void);
int			scene_destroy(t_scn *sc);
t_lht		*light_init(t_vec *o, double f, t_rgb rgb);
t_prm		*sphere_init(t_vec *o, double d, t_rgb rgb);
t_prm		*plane_init(t_vec *o, t_vec *n, t_rgb rgb);
t_prm		*square_init(t_vec *o, t_vec *n, double h, t_rgb rgb);
t_prm		*cylinder_init(t_vec *o, t_vec *n, double h, double d);
t_tri		*triangle_init(t_vec *a, t_vec *b, t_vec *c, t_rgb rgb);
void		scn_free_list_lht(t_lht *lst);
void		scn_free_list_cam(t_cam *lst);
void		scn_free_list_prm(t_prm *lst);
void		scn_free_list_tri(t_tri *lst);
void		scn_add(int objtype, void *obj, t_scn *sc);
double		radtodeg(double rad);
double		degtorad(double deg);
t_mat		*vector_vector_rotation_matrix(t_vec *v1, t_vec *v2);
void		intersect_destroy(t_hit *hit);
void		intersect_phit(t_hit *hit);
void		intersect_normal(t_hit *hit);
void		intersect_complements(t_hit *hit);
unsigned int	color_normal(t_vec *n);

t_vec		*g_x;
t_vec		*g_y;
t_vec		*g_z;

#endif
