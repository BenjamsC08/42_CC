/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 02:26:14 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 13:11:29 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_line(char *line, t_data *minishell, char *raw)
{
	if ((!line || !*line))
	{
		if (g_sig != 130)
			warning_heredoc(minishell, raw);
		return (0);
	}
	return (1);
}

static int	read_heredoc(int *pipefd, t_data *minishell, char *del, char *raw)
{
	char	*line;
	int		prompt;
	int		res;

	prompt = 1;
	while (42)
	{
		if (prompt && prompt--)
			ft_fprintf(minishell->hd_prompt_fd, "> ");
		line = get_next_line_free(0, 0);
		if (!is_line(line, minishell, raw))
			break ;
		if (ft_strchr(line, '\n'))
			prompt = 1;
		if ((!ft_strcmp_safe(line, del, &res) && !res)
			|| (ft_strcmp_safe(line, del, &res)) || g_sig == 130)
			break ;
		ft_fprintf(pipefd[1], "%s", line);
		free(line);
	}
	if (g_sig == 130)
		dup2(minishell->stdin, 0);
	if (!get_next_line_free(0, -42) && line)
		free(line);
	return (0);
}

void	heredoc_prompt_fd(t_data *minishell)
{
	minishell->hd_prompt_fd = open("/dev/tty", O_WRONLY);
	if (minishell->hd_prompt_fd == -1)
		minishell->hd_prompt_fd = 2;
}

int	*open_heredoc_pipe(t_data *minishell)
{
	int	*pipefd;

	pipefd = ft_calloc(2, sizeof(int));
	if (!pipefd)
		return (NULL);
	if (pipe(pipefd))
	{
		if (errno == EMFILE || errno == ENFILE)
			fd_error("execute_heredoc", minishell);
		return (free(pipefd), pipefd = NULL);
	}
	return (pipefd);
}

int	execute_heredoc(t_data *ms, t_cmd *current, int i)
{
	int		*pipefd;
	int		res;
	char	*delimiter;

	g_sig = 42;
	delimiter = setup_heredoc(ms, &pipefd, current, i);
	if (!delimiter)
		return (0);
	res = read_heredoc(pipefd, ms, delimiter, current->hd[i]);
	if (ms->hd_prompt_fd != -1)
		close(ms->hd_prompt_fd);
	if (res)
		return (free(pipefd), free(delimiter), res);
	current->infile = pipefd[0];
	if (pipefd[1] != -1)
		close(pipefd[1]);
	if (g_sig == 130)
	{
		free_list(get_head(&current));
		return (free(pipefd), free(delimiter), 0);
	}
	else
		g_sig = 0;
	return (free(pipefd), free(delimiter), 1);
}
