/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 07:44:12 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 15:14:13 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wait_all_children(t_cmd *head, int *pids, int *status)
{
	int		i;
	t_cmd	*current;

	i = 0;
	current = head;
	while (current)
	{
		if (pids[i] != -1)
			waitpid(pids[i], status, 0);
		i++;
		current = current->next;
	}
}

static void	handle_pipe_child(int prev, t_cmd *curr, t_cmd **head, t_data *ms)
{
	close_other_fds(curr, head);
	signal(SIGINT, sig_child);
	signal(SIGQUIT, SIG_DFL);
	if (handle_pipe_child_fds(prev, curr, ms))
	{
		reset_redirections_fds(ms);
		free_list(head);
		destroy_data(ms);
		exit(ms->exit_code);
	}
	if (!is_builtin_cmd(*curr->cmd))
		exec_non_builtin(curr, *head, ms);
	else if (is_builtin_cmd(*curr->cmd))
		ms->exit_code = exec_command_builtin(&curr, ms);
	reset_redirections_fds(ms);
	close_and_reassign_fd(&curr->outfile);
	if (!curr->next)
		close_and_reassign_fd(&ms->pipes[0]);
	free_list(head);
	destroy_data(ms);
	exit(ms->exit_code);
}

static int	skip_cmd(t_data *ms, t_cmd **current, int i, int *prev)
{
	int	tmp_pipe[2];

	ms->pids[i] = -1;
	close_and_reassign_fd(&ms->pipes[0]);
	close_and_reassign_fd(&ms->pipes[1]);
	if ((*current)->next)
	{
		if (pipe(tmp_pipe) == -1)
		{
			if (errno == EMFILE || errno == ENFILE)
				fd_error("skip_cmd", ms);
			return (1);
		}
		close_and_reassign_fd(&tmp_pipe[1]);
			*prev = tmp_pipe[0];
	}
	*current = (*current)->next;
	return (0);
}

static int	pipes_loop(t_data *ms, t_cmd *current, t_cmd **head)
{
	int	i;
	int	prev;

	i = -1;
	prev = -1;
	while (current && (++i || !i))
	{
		if ((!current->cmd || !*current->cmd))
		{
			if (skip_cmd(ms, &current, i, &prev))
				return (ms->exit_code = 1);
			continue ;
		}
		if (current->next && pipe(ms->pipes))
			return (handle_pipe_error(ms, "pipes_loop"));
		ms->pids[i] = fork();
		if (ms->pids[i] == -1)
			return (ms->exit_code = 1);
		if (ms->pids[i] == 0)
			handle_pipe_child(prev, current, head, ms);
		if (ms->pids[i] > 0)
			handle_parent_signal(ms, &prev);
		current = current->next;
	}
	return (cleanup_pipes(ms), ms->exit_code = 0);
}

int	exec_pipes(t_cmd **head, t_data *minishell)
{
	int		status;
	t_cmd	*current;

	if (!head || !*head)
		return (minishell->exit_code = 1);
	status = 128;
	current = *head;
	minishell->pids = ft_calloc(get_list_size(*head), sizeof(pid_t));
	if (!minishell->pids)
		return (minishell->exit_code = 1);
	pipes_loop(minishell, current, head);
	if (minishell->exit_code == 0)
	{
		wait_all_children(*head, minishell->pids, &status);
	}
	reset_redirections_fds(minishell);
	if (minishell->pids)
		free(minishell->pids);
	minishell->pids = NULL;
	signal(SIGINT, sig_parent);
	if (status > 127)
			minishell->exit_code = status >> 8;
	else if (status)
		minishell->exit_code = status + 128;
	return (minishell->exit_code);
}
