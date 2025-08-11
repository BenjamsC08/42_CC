/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:39:47 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 01:18:06 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_ms_history(t_data *ms, char *cmd)
{
	int	fd;

	if (!cmd || !*cmd)
		return (1);
	fd = open(HISTORY_PATH, O_WRONLY | O_CREAT | O_APPEND, 0600);
	if (fd == -1)
		return (fd_error("add_ms_history", ms), 1);
	if (fd != -1 && *cmd)
		ft_fprintf(fd, "%s\n", cmd);
	if (*cmd)
		add_history(cmd);
	if (fd != -1)
		close(fd);
	return (0);
}

static char	*rm_end_nl(char **s)
{
	size_t	i;
	char	*dst;

	if (!*s || !(*s)[0])
		return (NULL);
	dst = NULL;
	i = ft_strlen(*s);
	if ((*s)[i - 1] != '\n')
		return (*s);
	dst = ft_calloc(ft_strlen(*s), sizeof(char));
	if (!dst)
		return (free(*s), NULL);
	i = -1;
	while (++i < ft_strlen(*s) - 1)
		dst[i] = (*s)[i];
	free(*s);
	return (dst);
}

int	load_history(t_data *ms)
{
	int		fd;
	char	*s;

	fd = -1;
	if (access(HISTORY_PATH, F_OK | R_OK) == 0)
	{
		fd = open(HISTORY_PATH, O_RDONLY);
		if (fd == -1)
			return (fd_error("load_history", ms), 1);
	}
	while (42)
	{
		s = get_next_line(fd);
		s = rm_end_nl(&s);
		if (s)
		{
			add_history(s);
			free(s);
		}
		else
			break ;
	}
	if (fd != -1)
		close(fd);
	return (0);
}
