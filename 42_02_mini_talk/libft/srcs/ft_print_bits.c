/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moa <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 05:35:20 by moa               #+#    #+#             */
/*   Updated: 2025/02/04 06:06:46 by moa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int				i;
	unsigned char	tmp;

	octet = ft_reverse_bits(octet);
	i = -1;
	while (++i < 8)
	{
		tmp = (octet & 1);
		if (tmp == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		octet >>= 1;
	}
}
/**/
/*#include <stdio.h>*/
/**/
/*int	main(int argc, char **argv)*/
/*{*/
/*	int	nb;*/
/**/
/*	nb = ft_atoi(argv[1]);*/
/*	ft_print_bits(nb);*/
/*}*/
