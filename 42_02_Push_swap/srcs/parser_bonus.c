/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:41:28 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/05 11:38:48 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	only_digit(char **strs)
{
	int	i;
	int	j;

	i = -1;
	while (strs[++i])
	{
		j = -1;
		while (strs[i][++j])
		{
			if (j == 0 && (strs[i][j] == '-' || strs[i][j] == '+'))
			{
				if (ft_strlen(strs[i]) <= 1 || strs[i][j] == ' ')
					return (0);
				j++;
			}
			if (!ft_isdigit(strs[i][j]))
				return (0);
		}
	}
	return (1);
}

static int	is_int_size(char **strs)
{
	int				i;
	const double	max = 2147483648;
	double			nbr;

	i = 0;
	nbr = 0;
	while (strs[i])
	{
		nbr = ft_atol(strs[i]);
		if (nbr < 0)
		{
			if ((-nbr) > max)
				return (0);
		}
		else if (nbr >= max)
			return (0);
		i++;
	}
	return (1);
}

static int	is_double_in(char **strs)
{
	char	**strs2;
	int		i;
	int		j;

	strs2 = ft_strsdup(strs);
	if (!strs2)
		return (-1);
	i = -1;
	while (strs[++i])
	{
		j = -1;
		while (strs[++j])
		{
			if (i == j)
				continue ;
			if (ft_atoi(strs[i]) == ft_atoi(strs2[j]))
				return (free_strs(strs2), 1);
		}
	}
	free_strs(strs2);
	return (0);
}

static int	err_management(char ***strs)
{
	if (!only_digit(*strs))
		return (-1);
	if (!is_int_size(*strs))
		return (-2);
	if (is_double_in(*strs))
		return (-3);
	return (0);
}

char	**parse_arg(char **strs)
{
	const int	err = err_management(&strs);

	if (err)
	{
		free_strs(strs);
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return (strs);
}
