/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moa <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 06:12:15 by moa               #+#    #+#             */
/*   Updated: 2025/02/04 07:40:38 by moa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_pow_recursive(unsigned int nb, int power,
		unsigned long result)
{
	if (power == 0)
		return (result);
	if (result > ULONG_MAX / nb)
		return (ULONG_MAX);
	return (ft_pow_recursive(nb, power - 1, result * nb));
}

unsigned long	ft_pow(unsigned int nb, int power)
{
	if (power < 0)
		return (0);
	return (ft_pow_recursive(nb, power, 1));
}
