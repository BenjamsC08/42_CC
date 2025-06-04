/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moa <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 05:36:15 by moa               #+#    #+#             */
/*   Updated: 2025/02/04 05:42:53 by moa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_swap_bits(unsigned char octet)
{
	unsigned char	al;
	unsigned char	ah;

	al = octet >> 4;
	ah = octet << 4;
	return (ah + al);
}
/**/
/*#include <stdio.h>*/
/**/
/*int	main(int argc, char **argv)*/
/*{*/
/*	int	nb;*/
/**/
/*	nb = ft_atoi(argv[1]);*/
/*	printf("swap :%d", ft_swap_bits(nb));*/
/*}*/
