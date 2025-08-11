/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:09:17 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/04 09:01:47 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_only_digit(char *str)
{
	char	*src;

	src = str;
	while (*src)
	{
		if (!ft_isdigit(*src))
			return (0);
		src++;
	}
	return (1);
}

/*
int	main(void)
{
	if (ft_isalnum('8'))
		printf("ok\n");
	else
		printf("nok\n");
}*/
