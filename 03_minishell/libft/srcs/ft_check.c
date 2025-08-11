/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:50:31 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/26 22:50:33 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in(char s, const char *charset)
{
	char	*cs;

	cs = (char *)charset;
	if (cs)
	{
		while (*charset)
		{
			if (*charset == s)
				return (1);
			charset++;
		}
	}
	return (0);
}
