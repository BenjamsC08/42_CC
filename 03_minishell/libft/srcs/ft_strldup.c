/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:07:34 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/26 22:51:03 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(const char *s, size_t size)
{
	char	*str;
	char	*src;

	if (ft_strlen(s) < size)
		size = ft_strlen(s);
	str = (char *)ft_calloc((size + 1), sizeof(char));
	if (!str)
		return (0);
	src = str;
	while (*s && size > 0)
	{
		*(str++) = *(s++);
		size--;
	}
	return (src);
}
