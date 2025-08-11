/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pfd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:01:22 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/12 20:15:58 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_char_int_fd(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_put_str_int_fd(int fd, char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_put_str_int_fd(fd, "(null)"));
	while (*str)
		len += ft_put_char_int_fd(fd, *(str++));
	return (len);
}
