/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:55:24 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/26 22:50:23 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_boolean.h"
# include "ft_def.h"
# include "ft_fprintf.h"
# include "ft_limits.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

/*
 *			bit manip
 */
unsigned char	ft_reverse_bits(unsigned char octet);
unsigned int	ft_reverse_octets(unsigned int octets);
unsigned char	ft_swap_bits(unsigned char octet);
unsigned int	ft_swap_octets(unsigned int octets);
void			ft_print_bits(unsigned char octet);
void			ft_print_octets(unsigned int octets);
//		booltab and array whit an int
void			bit_set(t_booltab *tab, unsigned int pos);
void			bit_clear(t_booltab *tab, unsigned int pos);
unsigned int	bit_get(t_booltab tab, unsigned int pos);
void			bit_toggle(t_booltab *tab, unsigned int pos);
void			ba_set(t_boolarray *arr, unsigned int pos);
void			ba_clear(t_boolarray *arr, unsigned int pos);
unsigned int	ba_get(t_boolarray arr, unsigned int pos);
void			ba_toggle(t_boolarray *arr, unsigned int pos);
t_boolarray		create_bool_array(unsigned int num_bits);
void			free_bool_array(t_boolarray *arr);
/*
 *			char verification
 */
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isspace(char c);
int				ft_iswhitespace(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_is_in(char s, const char *charset);
/*
 *			string verification
 */
int				ft_only_alnum(char *str);
int				ft_only_alpha(char *str);
int				ft_only_ascii(char *str);
int				ft_only_digit(char *str);
int				ft_only_print(char *str);
int				ft_only_whitespace(char *str);
int				ft_only_isspace(char *str);
/*
 *			string manip ajouter strsiteri
 */
size_t			ft_strlen(const char *str);
int				ft_strlen_to(char *str, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp_safe(const char *s1, const char *s2, int *cmp);
char			*ft_strnstr(const char *big, const char *little, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t siz);
size_t			ft_strlcpy(char *dst, const char *src, size_t siz);
int				ft_atoi(const char *nptr);
double			ft_atol(const char *nptr);
char			*ft_strdup(const char *s);
char			*ft_strldup(const char *s, size_t size);
char			*ft_strdup_to(char **str, char c);
char			*ft_strdup_to_charset(char **str, char *charset);
char			*ft_strdup_only(char **str, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strfjoin(char *src, char *dest);
char			**ft_strsmerge(char **s1, char **s2);
char			*ft_str_add_char(char *str, char c);
/*int				ft_count_words(char *str, char c);*/
char			*ft_itoa(int n);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strcasestr(char *str, char *to_find);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strrev(char *str);
char			*ft_cut(char from, char *str, int l);
/*
 *			tab string manip
 */
int				ft_strslen(char **strs);
t_uint			ft_str_strs_len(char **strs);
char			**ft_strsdup(char **strs);
char			**ft_split(const char *str, char c);
char			*ft_unsplit(char **strs);
char			*ft_unsplit_with_sep(char **strs, char c);
char			*ft_unsplit_skip(char **strs, char c, int k);
void			free_strs(char **strs);
void			ft_free_strs(char **tab);
void			ft_free_fullstrs(char ***tab);
char			**ft_strsfjoin(char **src, char *dest);
void			print_strs(char **strs);
/*
 *			memory manip
 */
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
/*
 *			int verification
 */
int				ft_abs(int nb);
int				ft_isprime(int nb);
int				ft_next_prime(int nb);
int				ft_min(int nb1, int nb2);
int				ft_max(int nb1, int nb2);
/*
 *			int tab manip
 */
int				*ft_range(int min, int max);
int				*ft_rrange(int start, int end);
int				*ft_mintab(int *tab, unsigned int size);
int				*ft_maxtab(int *tab, unsigned int size);
/*
 *			file manip
 */
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
/*
 *			list manip
 */
// simple list
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
// double list
t_dlist			*ft_dlstnew(void *content);
int				ft_dlstsize(t_dlist *lst);
void			ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void			ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void			ft_dlstdelone(t_dlist *lst, void (*del)(void *));
t_dlist			*ft_dlstlast(t_dlist *lst);

#endif
