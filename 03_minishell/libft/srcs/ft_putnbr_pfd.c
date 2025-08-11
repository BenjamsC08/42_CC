/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pfd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:02:16 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/12 21:04:37 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_nbr_int_fd(int fd, int nb)
{
	char	*s;
	char	*s1;
	int		len;

	if (nb == 0)
		return (ft_put_char_int_fd(fd, '0'));
	s1 = ft_itoa(nb);
	s = s1;
	while (*s1)
		write(1, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	ft_put_uint_int_fd(int fd, unsigned int nb)
{
	char	*s;
	char	*s1;
	int		len;

	if (nb == 0)
		return (ft_put_char_int_fd(fd, '0'));
	s1 = ft_utoa(nb);
	if (!s1)
		return (0);
	s = s1;
	while (*s1)
		write(1, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	ft_put_hex_int_fd(int fd, unsigned int nbr, char type)
{
	char	*s;
	char	*s1;
	int		len;

	if (nbr == 0)
		return (ft_put_char_int_fd(fd, '0'));
	s1 = ft_xtoa(nbr, type);
	s = s1;
	if (nbr == 0)
		return (ft_put_char_int_fd(fd, '0'));
	while (*s1)
		write(1, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	ft_put_ptr_int_fd(int fd, unsigned long nbr)
{
	char	*s;
	char	*s1;
	int		len;

	if (nbr == 0)
		return (ft_put_str_int_fd(fd, "(nil)"));
	s1 = ft_xtoa(nbr, 'x');
	s = s1;
	write(1, "0x", 2);
	while (*s1)
		write(1, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len + 2);
}

int	ft_put_long_int_fd(int fd, long int nb)
{
	char	*s;
	char	*s1;
	int		len;

	if (nb == 0)
		return (ft_put_char_int_fd(fd, '0'));
	s1 = ft_ltoa(nb);
	if (!s1)
		return (0);
	s = s1;
	while (*s1)
		write(1, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}
