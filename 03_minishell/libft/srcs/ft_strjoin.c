/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:42:49 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/26 22:51:18 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*out;
	char	*s_1;
	char	*s_2;

	new = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!new)
		return (0);
	out = new;
	s_1 = (char *)s1;
	s_2 = (char *)s2;
	while (*s_1)
		*new ++ = *s_1++;
	while (*s_2)
		*new ++ = *s_2++;
	*new = 0;
	return (out);
}

char	*ft_strfjoin(char *src, char *dest)
{
	char	*new;
	char	*out;
	char	*s_1;
	char	*s_2;

	if (!src)
		return (0);
	if (!dest)
		return (free(src), NULL);
	new = (char *)ft_calloc((ft_strlen(src) + ft_strlen(dest) + 1),
			sizeof(char));
	if (!new)
		return (free(src), NULL);
	out = new;
	s_1 = (char *)src;
	s_2 = (char *)dest;
	while (*s_1)
		*new ++ = *s_1++;
	while (*s_2)
		*new ++ = *s_2++;
	*(new ++) = 0;
	new = NULL;
	free(src);
	return (out);
}

char	**ft_strsfjoin(char **src, char *add)
{
	char	**new;
	char	**out;
	char	**s_1;
	char	*s_2;

	new = (char **)ft_calloc((ft_strslen(src) + 2), sizeof(char *));
	if (!new)
		return (free_strs(src), NULL);
	out = new;
	s_1 = src;
	s_2 = add;
	while (s_1 && *s_1)
	{
		*new = ft_strdup(*s_1++);
		if (!*new)
			return (free_strs(out), free_strs(src), NULL);
		new ++;
	}
	if (s_2)
		*new = ft_strdup(s_2);
	if (!*new)
		return (free_strs(out), free_strs(src), NULL);
	return (free_strs(src), out);
}

char	**ft_strsmerge(char **s1, char **s2)
{
	char	**new;

	new = ft_strsdup(s1);
	while (*s2)
	{
		new = ft_strsfjoin(new, *s2);
		s2++;
	}
	free_strs(s1);
	return (new);
}
