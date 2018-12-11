/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:14:14 by srafe             #+#    #+#             */
/*   Updated: 2018/12/04 16:16:28 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(const char *str);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_atoi(const char *str);
void				*ft_bzero(void *buf, size_t count);
int					ft_isalnum(int a);
int					ft_isalpha(int a);
int					ft_isascii(int a);
int					ft_isdigit(int a);
int					ft_isprint(int a);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *arr);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *arr1, const void *arr2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *source, size_t n);
void				*ft_memset(void *buf, int ch, size_t count);
char				*ft_strcat(char *dest, const char *append);
char				*ft_strchr(const char *str, int ch);
void				ft_strclr(char *s);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void(*f)(char*));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
unsigned long		ft_strlcat(char *dest, char *src, unsigned long n);
size_t				ft_strlen(const char *str);
char				*ft_strtrim(char const *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char				**ft_strsplit(char const *s, char c);
char				*ft_strncat(char *dest, const char *append, size_t n);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnstr(const char *src1, const char *src2, size_t n);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strstr(const char *src1, const char *src2);
char				*ft_strsub(char const *s, unsigned int st, size_t len);
int					ft_tolower(int a);
int					ft_toupper(int a);
void				ft_lstfree(t_list *node);

#endif
