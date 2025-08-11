/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:32:52 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/12 20:38:07 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include "libft.h"

int	ft_fprintf(int fd, const char *str, ...);
int	ft_put_nbr_int_fd(int fd, int nb);
int	ft_put_uint_int_fd(int fd, unsigned int nb);
int	ft_put_hex_int_fd(int fd, unsigned int nbr, char type);
int	ft_put_ptr_int_fd(int fd, unsigned long nbr);
int	ft_put_char_int_fd(int fd, char c);
int	ft_put_str_int_fd(int fd, char *str);
int	ft_put_long_int_fd(int fd, long int nb);

#endif
