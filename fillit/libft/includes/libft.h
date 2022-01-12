/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:00:24 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/22 15:47:21 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "get_next_line.h"

/*
 *	Defines
 */
# define PI 3.14159265359
# define MAXINT 0x7FFFFFFF
# define MININT 0x80000000

/*
 *	Linked list
 */
typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
 *	Functions
 */
int				ft_sqrt(int nb);
void			ft_putchar(char c);
void			ft_putstr(const char *str);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
void			ft_putendl(const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strtrim(char const *s);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			**ft_strsplit(char const *s, char c);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
int				ft_strequ(const char *s1, const char *s2);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strmap(const char *s, char (*f)(char));
void			ft_strclr(char *s);
void			ft_strdel(char **as);
char			*ft_strnew(size_t size);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
void			ft_putnbr(int n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *haystack, const char *needle);
t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_memprint(const void *mem, size_t size);
int				ft_min(int n1, int n2);
int				ft_max(int n1, int n2);
int				ft_isspace(int c);
char			*ft_itoa_base(int n, unsigned int base);
int				ft_bintoi(const char *str);
int				ft_pow(int base, int power);
void			ft_strrev(char *str);
int				ft_abs(int num);
void			ft_putaddr(void *ptr);
void			*ft_memrealloc(void *ptr, size_t old_size, size_t new_size);
unsigned char	ft_bitrev(unsigned char octet);
unsigned char	ft_bitmod(unsigned char octet, unsigned char place,
					unsigned char bin);
unsigned char	ft_bitswap(unsigned char octet);
void			ft_bitprint(unsigned char octet);

#endif
