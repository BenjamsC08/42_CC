/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 02:18:42 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/13 02:19:10 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_file(char **buffer, int fd)
{
	int		read_bytes;
	char	*str;

	read_bytes = 1;
	while (read_bytes != 0)
	{
		str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!str)
			return ;
		read_bytes = read(fd, str, BUFFER_SIZE);
		if (read_bytes == 0)
		{
			free(str);
			return ;
		}
		if (*buffer != NULL)
			*buffer = ft_strjoin(*buffer, str);
		else
			*buffer = ft_strdup(str);
		if (found_newline(str))
			return ;
		free(str);
	}
}

static void	alloc_line(char **buffer, char **line)
{
	char	*str;
	int		len;

	str = *buffer;
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	*line = ft_calloc(len + 2, sizeof(char));
}

static void	extract_line(char **buffer, char **line)
{
	char	*buff;
	char	*str;

	if (*buffer == NULL)
		return ;
	buff = *buffer;
	alloc_line(buffer, line);
	str = *line;
	if (!str)
		return ;
	while (*buff && *buff != '\n')
		*(str++) = *(buff++);
	if (*buff == '\n')
		*str = *buff;
}

static void	del_line(char **buffer)
{
	char	*buff;
	char	*b;
	int		i;

	i = 0;
	b = *buffer;
	while (b[i] && b[i] != '\n')
		i++;
	if (b[i] == '\n')
		i++;
	if (i == 0)
		return ;
	buff = ft_strdup(b + i);
	if (!buff)
	{
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	free(*buffer);
	*buffer = buff;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	read_file(&buffer, fd);
	if (!buffer)
		return (NULL);
	extract_line(&buffer, &line);
	del_line(&buffer);
	if (line == NULL || !*line)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		free(line);
		line = NULL;
	}
	return (line);
}

/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*    char *str;*/
/**/
/*    while (1)*/
/*    {*/
/*        str = get_next_line(0); // Lecture depuis l'entrée standard*/
/*        if (str == NULL)        // EOF ou erreur*/
/*            break;*/
/*        printf("%s", str);*/
/*        // Si la ligne est juste un '\n', on arrête*/
/*        if (ft_strlen(str) == 1 && str[0] == '\n')*/
/*        {*/
/*            free(str);*/
/*            break;*/
/*        }*/
/*        free(str);*/
/*    }*/
/*    return (0);*/
/*}*/
