/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:22:02 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 12:54:15 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	warning_heredoc(t_data *ms, char *raw)
{
	ft_fprintf(ms->hd_prompt_fd,
		"\n%s: warning: here-document delimited by end-of-file (wanted `%s')\n",
		ms->name, raw);
	return (1);
}

char	*add_newline(char *s)
{
	char	*dst;
	int		i;

	dst = NULL;
	i = -1;
	if (!s)
		return (NULL);
	dst = ft_calloc(ft_strlen(s) + 2, sizeof(char));
	if (!dst)
		return (NULL);
	while (s[++i])
		dst[i] = s[i];
	dst[i] = '\n';
	return (dst);
}

static int	heredocs_loop(t_data *minishell, t_cmd *current)
{
	int	i;

	i = -1;
	if (current->hd)
	{
		while (current->hd[++i])
		{
			if (current->infile != -1)
				close(current->infile);
			if (!execute_heredoc(minishell, current, i))
				return (0);
			if (current->type_redir_in != HEREDOC)
			{
				if (current->infile != -1)
					close(current->infile);
				current->infile = -1;
			}
		}
	}
	return (1);
}

int	heredocs_processing(t_data *minishell, t_cmd *head)
{
	t_cmd	*current;
	int		res;

	if (!head)
		return (0);
	current = head;
	while (current)
	{
		res = heredocs_loop(minishell, current);
		if (!res)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

char	*setup_heredoc(t_data *ms, int **pipefd, t_cmd *current, int i)
{
	char	*delimiter;

	delimiter = NULL;
	heredoc_prompt_fd(ms);
	*pipefd = open_heredoc_pipe(ms);
	if (!*pipefd)
		return (NULL);
	delimiter = add_newline(current->hd[i]);
	if (!delimiter)
		return (free(*pipefd), NULL);
	return (delimiter);
}
