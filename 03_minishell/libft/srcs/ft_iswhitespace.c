/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moa <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 07:09:50 by moa               #+#    #+#             */
/*   Updated: 2025/03/04 09:02:36 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswhitespace(int c)
{
	if (c == '\t' || c == ' ' || c == '\r')
		return (1);
	return (0);
}

int	ft_only_whitespace(char *str)
{
	char	*src;

	src = str;
	while (*src)
	{
		if (!ft_iswhitespace(*src))
			return (0);
	}
	return (1);
}
