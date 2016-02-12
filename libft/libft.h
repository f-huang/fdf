/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:48:08 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/08 18:09:15 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define SIZE_DYNAM 16
# define BUFF_SIZE 2056

/*
**	GNL.H
*/

typedef struct	s_gnl
{
	int		fd;
	char	*lfo;
}				t_gnl;

/*
**	DYNAM.H
*/

typedef struct	s_dynam
{
	void	*data;
	size_t	type_size;
	size_t	max_elem;
	size_t	nb_elem;
}				t_dynam;

t_dynam			*ft_dynam_new(size_t type_size);
int				ft_dynam_append(t_dynam *dynam, void *new_data, size_t nb_data);
int				ft_dynam_trim(t_dynam *dynam);
void			ft_dynam_destroy(t_dynam **dynam);

/*
**	LIST.H
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_lstlen(t_list *list);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstaddend(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
**	PRINT FUNCTIONS
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbrendl(int n);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
**	CHAR FUNCTIONS
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isspace(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**	STRING FUNCTIONS
*/

int				ft_atoi(const char *str);
size_t			ft_strlen(char const *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *src, size_t n);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s);
char			*ft_trim_c(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
**	TAB FUNCTIONS
*/

size_t			ft_tablen(char **tab);
void			ft_tabfree(char **tab);
int				*ft_tabatoi(char **tab);

/*
**	NB FUNCTIONS
*/

char			*ft_itoa(int n);
unsigned int	ft_power_pos(unsigned int n, unsigned int p);

/*
**	MEM FUNCTIONS
*/

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_realloc(void *ptr, size_t size);

#endif
