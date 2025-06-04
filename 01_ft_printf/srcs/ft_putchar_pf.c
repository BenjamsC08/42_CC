/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:54:31 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/17 00:54:58 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char_int(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_str_int(char *str)
{
	int		len;

	len = 0;
	if (!str)
		return (ft_put_str_int("(null)"));
	while (*str)
		len += ft_put_char_int(*(str++));
	return (len);
}
