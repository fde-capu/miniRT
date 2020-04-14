/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:19:33 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/16 15:52:18 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
long long		ft_abs(long long value);
long long		ft_atoi(const char *str);
long long		ft_btod(char *nbr, int b_from);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_chrinset(char *r, char const *set);
char			*ft_chrtostr(char chr);
char			*ft_convert_base(const void *bdata, ...);
unsigned int	ft_countdigits(long long number);
unsigned int	ft_countdigits_ibase(long long number, unsigned int base);
char			*ft_dtob(long long n, int b_to);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
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
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr(char *s);
char			*ft_repchar(char c, unsigned int rpt);
void			ft_repchar_fd(char c, unsigned int rpt, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strcat(const char *dst, const char *src);
char			*ft_strcatx(char *dst, char *src);
char			*ft_strcatxl(char *s1, char *s2);
char			*ft_strcatxr(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchrcat(const char *dst, const char src);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
int				ft_stridentical(const char *s1, const char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(const char *str);
char			*ft_strnstr(const char *haystack, const char *needle, \
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *src);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strtrunc(char *str, int pos);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
double			ft_trig(double a_is_to, double b_as, double this_is_to_x);
char			*ft_ucase(char *str);
char			*ft_uitoa(unsigned int n);
char			*ft_ulltoa(unsigned long long n);
char			*ft_ultoa(unsigned long n);
char			*ft_ultoa(unsigned long n);
char			ft_whichar(const char *s, int x);
void			*ft_xlloc(void *arg1, void *arg2);

#endif
