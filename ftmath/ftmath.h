/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:04:58 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/23 14:55:56 by fde-capu         ###   ########.fr       */
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

typedef struct			s_triangle
{
	t_d3d				a;
	t_d3d				b;
	t_d3d				c;
	t_vec				n;
	t_rgb				rgb;
	struct s_triangle	*nx;
}						t_tri;

typedef struct			s_pimitive
{
	int					type;
	t_d3d				o;
	t_vec				n;
	double				h;
	double				d;
	t_rgb				rgb;
	struct s_pimitive	*nx;
}						t_prm;

typedef struct			s_camera
{
	t_d3d				o;
	t_vec				p;
	double				fov;
	struct s_camera		*nx;
}						t_cam;

typedef struct			s_amb_light
{
	double				f;
	t_rgb				rgb;
}						t_alt;

typedef struct			s_light
{
	t_d3d				o;
	double				f;
	t_rgb				rgb;
	struct s_light		*nx;
}						t_lht;

typedef struct			s_scene
{
	t_i2d				resolution;
	t_alt				ambient;
	t_cam				*cam_active;
	t_cam				*cam_list;
	t_lht				*lights;
	t_prm				*primitives;
	t_tri				*faces;
}						t_scn;

t_alt					amb_light_init(double f, t_rgb rgb);
t_cam					*cam_init(t_d3d o, t_vec p, double fov);
void					verbose_scene(t_scn *scn);
void					verb_faces(t_scn *scn);
void					verb_primitives(t_scn *scn);
void					verb_lights(t_scn *scn);
void					verb_cam(t_scn *scn);
void					verb_cam_active(t_scn *scn);
char					*prim_tpnm(int type);
t_scn					*scene_init(void);
int						scene_destroy(t_scn *sc);
t_lht					*light_init(t_d3d o, double f, t_rgb rgb);
t_prm					*sphere_init(t_d3d o, double d, t_rgb rgb);
t_prm					*plane_init(t_d3d o, t_vec n, t_rgb rgb);
t_prm					*square_init(t_d3d o, t_vec n, double h, t_rgb rgb);
t_prm					*cylinder_init(t_d3d o, t_vec n, double h, double d);
t_tri					*triangle_init(t_d3d a, t_d3d b, t_d3d c, t_rgb rgb);
void					scn_free_list_lht(t_lht *lst);
void					scn_free_list_cam(t_cam *lst);
void					scn_free_list_prm(t_prm *lst);
void					scn_free_list_tri(t_tri *lst);
void					scn_add(int objtype, void *obj, t_scn *sc);

# define TYPE_SP_NM		"Sphere"
# define TYPE_SP		1
# define TYPE_PL_NM		"Plane"
# define TYPE_PL		2
# define TYPE_SQ_NM		"Square"
# define TYPE_SQ		3
# define TYPE_CY_NM		"Cylinder"
# define TYPE_CY		4

# define TYPE_CAM_NM	"Camera"
# define TYPE_CAM		5
# define TYPE_LHT_NM	"Light"
# define TYPE_LHT		6
# define TYPE_PRM_NM	"Primitive"
# define TYPE_PRM		7
# define TYPE_TRI_NM	"Triangle"
# define TYPE_TRI		8

#endif
