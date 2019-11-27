/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:58:29 by mdaoud            #+#    #+#             */
/*   Updated: 2018/11/23 18:05:41 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
**		IO Functions
*/
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(void);
void			ft_putendl_fd(int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbrln(int n);
void			ft_putstr(char *s);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstrln(char *s);
void			ft_putstrln_fd(char *s, int fd);

/*
**		List Functions
*/
void			ft_lstappend(t_list **alst, t_list *node);
void			ft_lstclear(t_list **alst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void *content, size_t content_size);
void			ft_lstprint_node(t_list *lst);
void			ft_lstpush(t_list **alst, t_list *node);
void			ft_lstremove(t_list **list, t_list **node);
t_list			**ft_lstsplit(char *s, char c);

/*
** Memory Functions
*/
void			ft_bzero(void *ptr, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dest, void *src, int c, size_t n);
void			*ft_memchr(void *ptr, int c, size_t n);
int				ft_memcmp(void *s1, void *s2, size_t n);
void			*ft_memcpy(void *dest, void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dest, void *src, size_t n);
void			*ft_memset(void *ptr, int c, size_t n);

/*
** String Functions
*/
int				ft_atoi(char *s);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(char c);
char			*ft_itoa(int n);
char			*ft_strcat(char *dest, char *src);
char			*ft_strchr(char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(char *s1, char *s2);
int				ft_strcontains(char *charset, char c);
char			*ft_strcpy(char *dest, char *src);
void			ft_strdel(char **as);
char			*ft_strdup(char *s);
int				ft_strequ(char *s1, char *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char *s1, char *s2, int n);
size_t			ft_strlcat(char *dest, char *src, size_t n);
size_t			ft_strlen(char *s);
char			*ft_strmap(char *s, char (*f)(char));
char			*ft_strmapi(char *s, char(*f)(unsigned int, char));
char			*ft_strncat(char *dest, char *src, size_t n);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strncpy(char *dest, char *src, size_t n);
int				ft_strnequ(char *s1, char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(char *haystack, char *needle,
							size_t len);
char			*ft_strrchr(char *s, int c);
char  			*ft_strreplace(char *str, char from, char to);
char			*ft_strrev(char *str);
char			**ft_strsplit(char *s, char c);
char			*ft_strstr(char *haystack, char *needle);
char			*ft_strsub(char *s, unsigned int start, size_t len);
char			*ft_strtok(char *str, char *delim);
char			*ft_strtrim(char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
