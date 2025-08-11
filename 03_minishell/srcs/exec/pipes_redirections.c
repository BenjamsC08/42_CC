/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 07:52:54 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 14:13:46 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_and_reassign_fd(int *fd)
{
	if (*fd != -1)
	{
		close(*fd);
		*fd = -1;
	}
}

static int	setup_stdin(t_cmd *current, int prev_fd_to_read, t_data *ms)
{
	if (current->infile == -1 && prev_fd_to_read != -1)
	{
		if (dup2(prev_fd_to_read, STDIN_FILENO) == -1)
			return (fd_error("can't read from pipe", ms), 1);
		close(prev_fd_to_read);
	}
	else if (current->infile != -1)
	{
		if (dup2(current->infile, STDIN_FILENO) == -1)
			return (fd_error("can't read from pipe", ms), 1);
		close_and_reassign_fd(&current->infile);
		if (prev_fd_to_read != -1)
			close(prev_fd_to_read);
	}
	return (0);
}

static int	setup_stdout(t_cmd *current, t_data *minishell)
{
	if (current->outfile == -1 && minishell->pipes[1] != -1)
	{
		if (dup2(minishell->pipes[1], STDOUT_FILENO) == -1)
			return (fd_error("can't write into pipe", minishell), 1);
		close_and_reassign_fd(&minishell->pipes[1]);
		close_and_reassign_fd(&minishell->pipes[0]);
	}
	else if (current->outfile != -1)
	{
		if (dup2(current->outfile, STDOUT_FILENO) == -1)
			return (fd_error("can't write into pipe", minishell), 1);
		close_and_reassign_fd(&current->outfile);
		close_and_reassign_fd(&minishell->pipes[0]);
		close_and_reassign_fd(&minishell->pipes[1]);
	}
	return (0);
}

int	handle_pipe_child_fds(int prev, t_cmd *curr, t_data *minishell)
{
	int	res;

	if (!curr || !minishell)
		return (1);
	res = setup_stdin(curr, prev, minishell);
	if (res)
		return (res);
	res = setup_stdout(curr, minishell);
	if (is_builtin_cmd(*curr->cmd))
	{
		close_and_reassign_fd(&minishell->stdin);
		close_and_reassign_fd(&minishell->stdout);
	}
	return (res);
}

void	close_other_fds(t_cmd *current, t_cmd **head)
{
	t_cmd	*actual;

	actual = *head;
	while (actual)
	{
		if (actual != current)
		{
			if (actual->infile != -1)
				close(actual->infile);
			if (actual->outfile != -1)
				close(actual->outfile);
		}
		actual = actual->next;
	}
}
