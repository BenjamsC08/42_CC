/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moa <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 05:37:04 by moa               #+#    #+#             */
/*   Updated: 2025/02/04 05:57:51 by moa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	tmp;

	i = -1;
	while (++i < 8)
	{
		tmp <<= 1;
		tmp |= (octet & 1);
		octet >>= 1;
	}
	return (tmp);
}
/**/
/*#include <stdio.h>*/
/**/
/*int	main(int argc, char **argv)*/
/*{*/
/*	int	nb;*/
/**/
/*	nb = ft_atoi(argv[1]);*/
/*	printf("swap :%d", ft_reverse_bits(nb));*/
/*}*/
