/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:07:20 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 15:07:55 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	single_cmd_child(t_cmd *current, t_data *ms)
{
	t_cmd	**head;

	head = get_head(&current);
	signal(SIGINT, sig_child);
	signal(SIGQUIT, SIG_DFL);
	exec_non_builtin(current, *head, ms);
	reset_redirections_fds(ms);
	free_list(head);
	destroy_data(ms);
	exit(ms->exit_code);
}

static int	exec_single_cmd(t_cmd *current, t_data *ms)
{
	int		status;
	pid_t	pid;

	pid = -42;
	status = 0;
	if (!current->cmd)
		return (ms->exit_code = 0);
	if (!*current->cmd || start_redirections_fds(current, ms) == -1)
		return (ms->exit_code = 1);
	if (!is_builtin_cmd(*current->cmd))
		pid = fork();
	if (pid == -1)
		return (ms->exit_code = 1);
	if (pid == 0)
		single_cmd_child(current, ms);
	else if (is_builtin_cmd(*current->cmd))
		ms->exit_code = exec_command_builtin(&current, ms);
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	check_status(&status, ms);
	signal(SIGINT, sig_parent);
	if (ms->exit_code == 0)
		ms->exit_code = status;
	return (reset_redirections_fds(ms), ms->exit_code);
}

int	execute(t_data *minishell, t_cmd *head)
{
	if (!heredocs_processing(minishell, head))
	{
		if (g_sig != 130)
		{
			free_list(&head);
			minishell->exit_code = 1;
		}
		else
			minishell->exit_code = 130;
		return (ft_free_fullstrs(&minishell->cmd), minishell->exit_code);
	}
	if (infile_redirections(minishell, head))
		return (ft_free_fullstrs(&minishell->cmd), free_list(&head), 1);
	if (output_redirections(minishell, head))
		return (ft_free_fullstrs(&minishell->cmd), free_list(&head), 1);
	if (head->pipe == TRUE)
		exec_pipes(&head, minishell);
	else
		exec_single_cmd(head, minishell);
	return (0);
}

void	exec_non_builtin(t_cmd *curr, t_cmd *head, t_data *ms)
{
	int	path_status;

	path_status = is_valid_absolute_path(*curr->cmd);
	if (!is_builtin_cmd(*curr->cmd))
	{
		if (!is_absolute_path(*curr->cmd))
		{
			if (find_cmd_path(curr->cmd, ms, ms->env)
				&& find_cmd_path(curr->cmd, ms, ms->paths))
				clean_and_exit(&head, ms, ms->exit_code);
		}
		else if (path_status == 1 || path_status == -1)
			handle_path_error(path_status, curr, ms, head);
		else if (path_status == 2)
		{
			ft_fprintf(2, "%s: %s: Is a directory\n", ms->name, *curr->cmd);
			reset_std_fd(ms);
			clean_and_exit(&head, ms, 126);
		}
	}
	reset_std_fd(ms);
	check_env_size(ms, &head, curr);
	execve(curr->cmd[0], curr->cmd, ms->env);
}

int	exec_command_builtin(t_cmd **current, t_data *data)
{
	int	res;

	res = 126;
	if (!ft_strncmp((const char *)(*current)->cmd[0], "cd", 2))
		res = change_directory((*current)->cmd, data);
	if (!ft_strncmp((const char *)(*current)->cmd[0], "pwd", 3))
		res = actual_directory(data);
	if (!ft_strncmp((const char *)(*current)->cmd[0], "env", 3))
		res = print_env(data);
	if (!ft_strncmp((const char *)(*current)->cmd[0], "export", 6))
		res = export_env(data, (*current)->cmd[1]);
	if (!ft_strncmp((const char *)(*current)->cmd[0], "unset", 5))
		res = unset_env(data, (*current)->cmd[1]);
	if (!ft_strncmp((const char *)(*current)->cmd[0], "exit", 4))
		return (quit_ms(data, (*current)->cmd + 1));
	if (!ft_strncmp((const char *)(*current)->cmd[0], "echo", 4))
		res = echo_func((*current)->cmd);
	return (res);
}
