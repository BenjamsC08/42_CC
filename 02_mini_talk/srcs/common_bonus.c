/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:40:13 by benjamsc          #+#    #+#             */
/*   Updated: 2025/02/26 11:40:28 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	only_digits(char *str)
{
	char	*src;

	src = str - 1;
	while (*(++src))
	{
		if (!ft_isdigit(*src))
			return (0);
	}
	return (1);
}

void	err_handler(int err)
{
	if (err == -1)
		return (ft_putstr_fd("wrong entry -1", 2));
	if (err == -2)
		return (ft_putstr_fd("wrong entry -2", 2));
}
