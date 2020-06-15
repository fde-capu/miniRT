/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:19:33 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 08:14:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <stdarg.h>

# include "libft_types.h"
# include "debug.h"
# include "keys.h"

long long		ft_abs(long long value);
double			ft_atod(const char *str);
t_d3d			ft_atod3d(const char *str);
long long		ft_atoi(const char *str);
t_rgb			ft_atorgb(char *str);
t_vec			ft_atovec(const char *str);
long long		ft_btod(char *nbr, int b_from);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_chrinset(char *r, char const *set);
char			*ft_chrtostr(char chr);
char			*ft_convert_base(const void *bdata, ...);
unsigned int	ft_countdigits(long long number);
unsigned int	ft_countdigits_ibase(long long number, unsigned int base);
t_d3d			ft_d3d(double x, double y, double z);
char			*ft_d3dtoa(t_d3d vec);
char			*ft_dtoa(double d);
char			*ft_dtob(long long n, int b_to);
char			*ft_findstr(char *str, char c);
char			*ft_get_word(char *line);
t_i2d			ft_i2d(int x, int y);
void			ft_init(void);
int				ft_is_comment(char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isnumber(char *str);
int				ft_isprint(int c);
char			*ft_itoa(int n);
t_rgb			ft_itorgb(int i);
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
double			ft_pow(double a, double e);
char			*ft_ptoa(void *p);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr(char *s);
void			ft_putstr_nl(char *s);
char			*ft_removequotes(char *quoted);
char			*ft_repchar(char c, unsigned int rpt);
void			ft_repchar_fd(char c, unsigned int rpt, int fd);
t_rgb			ft_rgb(unsigned char r, unsigned char b, unsigned char g);
char			*ft_rgbtoa(t_rgb rgb);
int				ft_rgbtoi(t_rgb rgb);
char			**ft_split(char const *s, char c);
char			*ft_strcat(const char *dst, const char *src);
char			*ft_strcatchrx(char *dst, char *c);
char			*ft_strcatx(char *dst, char *src);
char			*ft_strcatxl(char *s1, char *s2);
char			*ft_strcatxr(char *s1, char *s2);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchrcat(const char *dst, const char src);
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
char			*ft_strchr(char *str, char c);
char			*ft_strnchr(char *str, char c);
char			*ft_strnew(void);
char			*ft_strnstr(const char *haystack, const char *needle, \
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *src);
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
char			ft_whichar(const char *s, int x);
void			*ft_x(void *a1, void *a2);
void			*ft_xlloc(void *arg1, void *arg2);
u_int8_t		ft_bit8_get(u_int8_t *data, u_int8_t bit);
void			ft_bit8_set(u_int8_t *data, u_int8_t bit, u_int8_t val);
void			ft_bit8_tog(u_int8_t *data, u_int8_t bit);
char			*ft_bit8_str(u_int8_t data);
char			*ft_removequotes(char *quoted);

# define TRIM_SET			" \t\n\r\v\f"
# define COMMENT_SET		"#"
# define DIV				" :: "
# define DOUBLE_PRECISION	10
# define DECIMAL_POINT		"."
# define DEB_STR_ENCLOSURE	"\""

#endif
