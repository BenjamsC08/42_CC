/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:56:08 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/17 00:56:44 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_intlen(unsigned int nb, char type)
{
	int	i;

	i = 0;
	if (type != 'u' && nb > 2147483647)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_xlen(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

int	ft_lxlen(unsigned long nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}
