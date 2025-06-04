/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:46:52 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/20 10:43:56 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		found_newline(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *s);

char	*get_next_line(int fd);

#endif
