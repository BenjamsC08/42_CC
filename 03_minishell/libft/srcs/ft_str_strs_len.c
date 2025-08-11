/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_strs_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:52:09 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/26 22:52:11 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uint	ft_str_strs_len(char **strs)
{
	t_uint	i;
	t_uint	l;
	t_uint	total_len;

	if (!strs)
		return (0);
	l = 0;
	total_len = 0;
	while (strs[l])
	{
		i = 0;
		while (strs[l][i])
			i++;
		total_len += i;
		l++;
	}
	return (total_len);
}
