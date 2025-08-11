/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:21:12 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/04 09:00:44 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

int	ft_only_alnum(char *str)
{
	char	*src;

	src = str;
	while (*src)
	{
		if (!ft_isalnum(*src))
			return (0);
	}
	return (1);
}

/*
int	main(void)
{
	if (ft_isalnum(68))
		printf("ok\n");
	else
		printf("nok\n");
}*/
