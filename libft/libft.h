/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:19:33 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/24 16:44:51 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** v0.0.1
** Incompatibility!
** ft_chrinset used to be `(char *, char *)`, now is `(char, char *)`.
** Change previous version to `ft_strchrinset (char *, char *)` to fix it.
**
** !!!! Attention! This file has <ftmath.h> !!!!!
*/

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <stdarg.h>

# include "defines_libft.h"
# include "types_libft.h"
# include "debug.h"
# include "keys.h"
# include "../ftmath/ftmath.h"

long long		ft_abs(long long value);
double			ft_abs_double(double value);
unsigned int	ft_argbtoi(t_rgb rgb);
char			*ft_args(int argc, char **argv, char *test);
double			ft_atod(const char *str);
long long		ft_atoi(const char *str);
t_rgb			ft_atorgb(char *str);
long long		ft_btod(char *nbr, int b_from);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_ceil(double d);
char			*ft_check(const char *str, char *reg);
int				ft_chrinset(char r, char const *set);
int				ft_chrsame(char a, char b);
char			*ft_chrtostr(char chr);
char			*ft_convert_base(const void *bdata, ...);
unsigned int	ft_countdigits(long long number);
unsigned int	ft_countdigits_ibase(long long number, unsigned int base);
void			ft_die(const char *msg, int err);
char			*ft_dtoa(double d);
char			*ft_dtob(long long n, int b_to);
int				ft_enclosure(char *io, char h);
char			*ft_findstr(char *str, char c);
char			*ft_get_word(char *line);
int				ft_head_read(char **h, char *r, char *key);
void			ft_init(void);
char			*ft_inside(char *h);
char			*ft_inskip(char *h);
int				ft_insp_count(char *h, char x);
char			**ft_insplit(const char *str, char x);
int				ft_is_comment(char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isnumber(char *str);
int				ft_isprint(int c);
int				ft_isupper(int c);
char			*ft_itoa(int n);
t_rgb			ft_itoargb(unsigned int i);
t_rgb			ft_itobgra(unsigned int i);
char			*ft_join(char **split);
char			*ft_lastchar(char *str);
int				ft_lastchar_eq(char *str, char chr);
char			*ft_lcase(char *str);
char			*ft_lltoa(signed long long n);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
char			*ft_ltoa(long n);
void			ft_max2d(int *x, int *y, int x_lim, int y_lim);
void			*ft_memcat(void *m1, void *m2, int s1, int s2);
void			*ft_memcatx(void *m1, void *m2, int s1, int s2);
void			*ft_memcatxl(void *m1, void *m2, int s1, int s2);
void			*ft_memcatxr(void *m1, void *m2, int s1, int s2);
void			*ft_memccpy(void *dst, const void *src, \
					int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
double			ft_pow(double a, int e);
char			*ft_ptoa(void *p);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr(char *s);
void			ft_putstr_nl(char *s);
char			*ft_removequotes(char *quoted);
char			*ft_repchar(char c, unsigned int rpt);
void			ft_repchar_fd(char c, unsigned int rpt, int fd);
t_rgb			ft_rgb(unsigned char a, \
					unsigned char r, unsigned char g, unsigned char b);
char			*ft_rgbtoa(t_rgb rgb);
int				ft_rgbtoi(t_rgb rgb);
char			**ft_split(char const *s, char c);
char			**ft_split_set(char const *s, const char *c);
size_t			ft_strarrlen(char **s);
int				ft_strbegins(const char *str, const char *beg);
char			*ft_strcat(const char *dst, const char *src);
char			*ft_strcatchrx(char *dst, char *c);
char			*ft_strcatx(char *dst, char *src);
char			*ft_strcatxl(char *s1, char *s2);
char			*ft_strcatxr(char *s1, char *s2);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchr(char *str, char c);
char			*ft_strchrcat(const char *dst, const char src);
int				ft_strchrinset(char *t, char const *sset);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
void			ft_strfree2d(char **str);
int				ft_stridentical(const char *s1, const char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_str(char *str);
char			*ft_strnchr(char *str, char c);
char			*ft_strnew(void);
char			*ft_strnstr(const char *haystack, const char *needle, \
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *src);
char			*ft_strstr(const char *a, const char *b);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strtrimx(char *s1, char *set);
char			*ft_strtrunc(char *dst, char trunc);
char			*ft_strtrunc_pos(char *str, int pos);
char			*ft_strx(char *s1, char *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_trim(char *str);
double			ft_trig(double a_is_to, double b_as, double this_is_to_x);
char			*ft_ucase(char *str);
char			*ft_uctoa(unsigned char uc);
char			*ft_uitoa(unsigned int n);
char			*ft_ulltoa(unsigned long long n);
char			*ft_ultoa(unsigned long n);
char			*ft_ultoa(unsigned long n);
char			*ft_vtoa(t_vec *vec);
char			ft_whichar(const char *s, int x);
void			*ft_x(void *a1, void *a2);
void			*ft_xlloc(void *arg1, void *arg2);
u_int8_t		ft_bit8_get(u_int8_t *data, u_int8_t bit);
void			ft_bit8_set(u_int8_t *data, u_int8_t bit, u_int8_t val);
void			ft_bit8_tog(u_int8_t *data, u_int8_t bit);
char			*ft_bit8_str(u_int8_t data);
char			*ft_removequotes(char *quoted);
int				loop_2d(int x, int y);

/*
** lstdbl
*/

t_dbl			*lstdbl_addlast(t_dbl *h, double d);
t_dbl			*lstdbl_copy(t_dbl *h);
void			lstdbl_destroy(t_dbl *dbl);
t_dbl			*lstdbl_last(t_dbl *h);
void			lstdbl_mult_element(t_dbl *ld, int e, int m);
t_dbl			*lstdbl_new(double val);
double			lstdbl_pop(t_dbl *h);

/*
** Regex related.
*/

int				rgx_fun_in(int fun);
void			rgx_maybe_free(char *blk, int fun);
int				rgx_function_n(char *rh);
char			*rgx_chk_function(int mode, char *sh, char *blk);
void			rgx_set_rep(int *mm, char *mod);
char			*rgx_sk_mod(char *mod);
int				rgx_mm_manual(int pos, char *keys);
void			rgx_mm_mod(int *mm, int oblig, int optio);

/*
** Verboses:
*/

void			verb_cam(t_scn *scn);
void			verb_cam_active(t_scn *scn);
void			verb_faces(t_scn *scn);
void			verb_lights(t_scn *scn);
void			verb_primitives(t_scn *scn);
void			verbose_scene(t_scn *scn);

/*
** Math related:
*/

t_mat			*axis_angle_rotation(t_vec *axis, double theta);
void			vector_append_val(t_vec *vec, double val);
t_vec			*vector_build(int len, ...);
t_vec			*vector_copy(t_vec *a);
t_vec			*vector_cross_product(t_vec *x, t_vec *y);
void			vector_destroy(t_vec *vec);
double			vector_dot_product(t_vec *v1, t_vec *v2);
t_vec			*vector_empty(int len);
int				vector_equal(t_vec *a, t_vec *b);
double			vector_get_element(t_vec *vec, int i);
double			vector_magnitude(t_vec *v);
t_vec			*vector_matrix_multiply(t_vec *left, t_mat *right);
void			vector_multiply_element(t_vec *vec, int elem, double factor);
t_vec			*vector_new(void);
void			vector_normalize(t_vec *mv);
int				vector_parallel(t_vec *x, t_vec *y);
double			vector_pop(t_vec *vec);
void			vector_put_element(t_vec *vec, int pos, double d);
int				vector_range_check_boundaries(t_mat *m, t_vec *range);
void			vector_range_fix(t_vec *range);
t_vec			*vector_scalar_multiply(t_vec *a, double scalar);
t_vec			*vector_scalar_sum(t_vec *vec, double val);
t_vec			*vector_scale(t_vec *vec, t_vec *xyz);
t_vec			*vector_subtract(t_vec *a, t_vec *b);
t_vec			*vector_sum(t_vec *a, t_vec *b);
void			vector_transform(t_vec **vec, t_mat *trans);
t_mat			*vector_transpose(t_vec *v);
t_vec			*vector_translate(t_vec *vec, t_vec *xyz);
double			vector_vector_angle_deg(t_vec *x, t_vec *y);
double			vector_vector_angle_rad(t_vec *x, t_vec *y);
t_vec			*vectorx(t_vec *old, t_vec *new);
t_vec			*matvec_get_element(t_mvec *mv, int i, int j);
void			matvec_insert_at_pos(t_mvec *mv, int i, int j, t_vec *vec);
void			matvec_destroy(t_mvec *mat);
t_mvec			*matvec_new(void);
t_vec			*ft_atov(char *str);
int				is_normalized(t_vec *vec);
t_mat			*matrix_adjoint(t_mat *m);
t_mat			*matrix_build(int m, int n, ...);
t_mat			*matrix_checkers_sign(t_mat *a);
t_mat			*matrix_copy(t_mat *a);
void			matrix_destroy(t_mat *mat);
double			matrix_determinant(t_mat *a);
t_mat			*matrix_diagonal(t_vec *dvec);
t_mat			*matrix_empty(int m, int n);
double			matrix_get_element(t_mat *mat, int i, int j);
t_mat			*matrix_get_line(t_mat *m, int i);
t_vec			*matrix_get_line_transposed(t_mat *m, int i);
t_vec			*matrix_get_vector(t_mat *m, int j);
t_dbl			*matrix_goto_element(t_mat *mat, int m, int n);
t_mat			*matrix_identity(int s);
t_mat			*matrix_inverse(t_mat *a);
t_mat			*matrix_matrix_multiply(t_mat *left, t_mat *right);
t_mat			*matrix_minor(t_mat *a, int i, int j);
t_mat			*matrix_new(void);
t_mat			*matrix_new_mn(int m, int n);
t_mat			*matrix_of_cofactors(t_mat *a);
t_mat			*matrix_of_minors(t_mat *a);
t_mat			*matrix_of_vectors_transposed(t_vec *v1, t_vec *v2, t_vec *v3);
void			matrix_put_element(t_mat *dst, int i, int j, double d);
void			matrix_put_matrix(t_mat *dest, t_mat *ref, int i, int j);
t_mat			*matrix_scalar_multiply(t_mat *b, double s);
void			matrix_screen(t_mat *dst, t_mat *src);
t_mat			*matrix_sum(t_mat *a, t_mat *b);
void			matrix_switch_elements(t_mat *mat, t_vec *tvec);
void			matrix_transform(t_mat **mat, t_mat *trans);
t_mat			*matrix_transpose(t_mat *a);
t_vec			*matrix_vector_multiply(t_mat *left, t_vec *right);
t_mat			*matrixx(t_mat *old, t_mat *new);
char			*primitive_type_number(int type);
t_ray			*ray_build(t_vec *a, t_vec *b);
void			ray_destroy(t_ray *ray);
double			hit_sphere(t_ray *ray, t_prm *sphere);
double			hit_square(t_ray *ray, t_prm *square);
double			hit_minimal(double t);
double			hit_disc(t_ray *ray, t_prm *disc);
t_vec			*hit_point(t_ray *ray, double t);
void			missing_up_gambiarra(t_vec *p, t_vec **v_up, t_vec **v_left);
double			hit_triangle(t_ray *ray, t_vec *a, t_vec *b, t_vec *c);
double			hit_plane(t_ray *ray, t_prm *plane);

/*
** Debugs:
*/

int				debug_pass(void);
void			debug(char *str, char *val, int *ival);
void			debug_body(char *str, char *val, int ival);
void			debug_int(char *str, int ival);
void			debug_int2(char *str, int val, int val2);
void			subdebug_int(char *str, int ival, int subdeb);
void			subdebug_int2(char *str, int val, int val2, int subdeb);
void			debug_str(char *str, char *val);
void			debug_str2(char *str, char *val, char *val2);
void			debug_str_only(char *str);
void			debug_double(char *str, double val);
void			debug_double2(char *str, double val, double val2);
void			debug_rgb(char *str, t_rgb rgb);
void			debug_vector(char *str, t_vec *vec);
void			debug_str_add(char *str, void *add);
void			debug_str_str(char *str1, char *str2);
void			debug_t_dbl(char *str, t_dbl *dbl);
void			debug_matrix(char *str, t_mat *mat);
void			debug_matrix_2(t_mat *mat);
void			debug_matrix_of_vectors(char *str, t_mvec *mat);
void			debug_matrix_single_line(t_mat *mat);

#endif
