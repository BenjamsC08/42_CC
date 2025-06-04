/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:00:14 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/18 13:44:34 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	char	*out;
	char	*s_1;
	char	*s_2;

	new = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (! new)
		return (0);
	out = new;
	s_1 = (char *)s1;
	s_2 = (char *)s2;
	while (*s_1)
		*new++ = *s_1++;
	while (*s_2)
		*new++ = *s_2++;
	*new = 0;
	free(s1);
	return (out);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*ptr;
	char			*s;
	unsigned int	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	s = (char *)ptr;
	i = -1;
	while (++i < (nmemb * size))
		s[i] = 0;
	return (ptr);
}

char	*ft_strdup(char *s)
{
	int		l_src;
	char	*str;
	char	*src;

	l_src = ft_strlen(s);
	str = (char *)ft_calloc((l_src + 1), sizeof(char));
	if (! str)
		return (0);
	src = str;
	while (*s)
		*(str++) = *(s++);
	*str = '\0';
	return (src);
}

int	found_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			free(str);
			return (1);
		}
		i++;
	}
	return (0);
}
