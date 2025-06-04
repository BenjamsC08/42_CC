/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:49:43 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/17 00:50:27 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	int				len_nb;
	char			*str_nb;
	unsigned int	nbr;

	nbr = n;
	len_nb = ft_intlen(nbr, 'i');
	str_nb = (char *)malloc(len_nb + 1);
	if (! str_nb)
		return (0);
	*(str_nb + len_nb) = 0;
	if (n < 0)
		nbr = -nbr;
	while ((len_nb--) > 0)
	{
		str_nb[len_nb] = (nbr % 10 + '0');
		nbr /= 10;
	}
	if (n < 0)
		*str_nb = '-';
	return (str_nb);
}

char	*ft_utoa(unsigned int n)
{
	int				len;
	char			*str;
	unsigned int	nbr;

	nbr = n;
	len = ft_intlen(nbr, 'u');
	str = (char *)malloc(len + 1);
	if (! str)
		return (0);
	*(str + len) = 0;
	while ((len--) > 0)
	{
		str[len] = (nbr % 10 + '0');
		nbr /= 10;
	}
	return (str);
}

char	*ft_xtoa(unsigned int nbr, char type)
{
	char	*base;
	char	*str;
	int		len;

	base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	len = ft_xlen(nbr);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	*(str + len) = 0;
	while ((len--) > 0)
	{
		str[len] = base[nbr % 16];
		nbr /= 16;
	}
	return (str);
}

char	*ft_lxtoa(unsigned long nbr)
{
	char	*base;
	char	*str;
	int		len;

	base = "0123456789abcdef";
	len = ft_lxlen(nbr);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	*(str + len) = 0;
	while ((len--) > 0)
	{
		str[len] = base[nbr % 16];
		nbr /= 16;
	}
	return (str);
}
