/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:55:24 by benjamsc          #+#    #+#             */
/*   Updated: 2025/02/04 07:58:43 by moa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_boolean.h"
# include "ft_limits.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

unsigned char		ft_reverse_bits(unsigned char octet);
unsigned char		ft_swap_bits(unsigned char octet);
void				ft_print_bits(unsigned char octet);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_iswhitespace(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

size_t				ft_strlen(const char *str);
int					ft_strslen(char **strs);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t siz);
size_t				ft_strlcpy(char *dst, const char *src, size_t siz);
int					ft_atoi(const char *nptr);
double				ft_atol(const char *nptr);
char				*ft_strdup(const char *s);
char				**ft_strsdup(char **strs);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_straddchar(char *s1, char c);
char				**ft_split(const char *str, char c);
void				free_strs(char **strs);
int					ft_count_words(char *str, char c);
char				*ft_itoa(int n);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strcasestr(char *str, char *to_find);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strrev(char *str);

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_calloc(size_t nmemb, size_t size);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstpenultimate(t_list *lst);

int					*ft_range(int min, int max);
int					*ft_rrange(int start, int end);

unsigned long		ft_pow(unsigned int nb, int power);
void				ft_abs(int *nb);
int					ft_factorial(int nb);
int					ft_isprime(int nb);
int					ft_next_prime(int nb);

#endif
