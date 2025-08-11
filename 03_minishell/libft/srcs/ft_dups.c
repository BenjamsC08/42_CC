/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dups.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:51:50 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/26 22:51:52 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_to(char **str, char c)
{
	char	*out;
	char	*s;

	if (!*str || !c)
		return (NULL);
	out = NULL;
	s = *str;
	if (*s == c)
		s++;
	while (*s && *s != c)
		out = ft_str_add_char(out, *(s++));
	if (*s == c)
		s++;
	*str = s;
	return (out);
}

char	*ft_strdup_to_charset(char **str, char *charset)
{
	char	*out;
	char	*s;

	if (!*str || !charset)
		return (NULL);
	out = NULL;
	s = *str;
	while (*s && !ft_is_in(*s, charset))
	{
		out = ft_str_add_char(out, *(s++));
	}
	*str = s;
	return (out);
}

char	*ft_strdup_only(char **str, char c)
{
	char	*out;
	char	*s;

	if (!*str || !c)
		return (NULL);
	out = NULL;
	s = *str;
	while (*s && *s == c)
		out = ft_str_add_char(out, *(s++));
	*str = s;
	return (out);
}
