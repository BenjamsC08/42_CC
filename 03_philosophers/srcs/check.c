/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:02:16 by benjamsc          #+#    #+#             */
/*   Updated: 2025/07/12 17:02:16 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	only_digit(char *str)
{
	char	*src;

	src = str - 1;
	while (*(++src))
	{
		if (!(*src >= '0' && *src <= '9'))
			return (0);
	}
	return (1);
}

static int	bigger_than_int(char *str)
{
	long	nb;

	nb = atol(str);
	if (!nb)
		return (-1);
	if (nb > INT_MAX)
		return (1);
	return (0);
}

static int	is_negative(char *str)
{
	int	nb;

	nb = ft_atoi(str);
	if (nb < 0)
		return (1);
	return (0);
}

int	check_args(int argc, char **argv, int **tab_out)
{
	int	i;
	int	*tab;

	i = -1;
	while (++i < argc)
	{
		if (!only_digit(argv[i]))
			return (0);
		if (bigger_than_int(argv[i]) || is_negative(argv[i]))
			return (0);
	}
	i = -1;
	tab = ft_calloc(argc + 1, sizeof(int));
	if (!tab)
		return (0);
	while (++i < argc)
	{
		tab[i] = ft_atoi(argv[i]);
		if (!tab[i])
			return (free(tab), 0);
	}
	*tab_out = tab;
	return (1);
}
