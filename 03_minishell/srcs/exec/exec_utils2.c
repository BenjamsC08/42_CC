/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:11:13 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 15:12:32 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_parent_signal(t_data *minishell, int *prev_fd_to_read)
{
	signal(SIGINT, SIG_IGN);
	close_and_reassign_fd(&minishell->pipes[1]);
	close_and_reassign_fd(prev_fd_to_read);
	*prev_fd_to_read = minishell->pipes[0];
}

static int	is_directory(const char *path)
{
	struct stat	sb;

	if (stat(path, &sb) == 0)
		return (S_ISDIR(sb.st_mode));
	return (0);
}

int	is_absolute_path(char *cmd)
{
	if (*cmd == '.' || ft_is_in('/', cmd))
		return (1);
	return (0);
}

int	is_valid_absolute_path(char *cmd)
{
	if (is_directory(cmd))
		return (2);
	if (access(cmd, F_OK))
		return (-1);
	if (access(cmd, X_OK) == 0)
		return (0);
	return (1);
}

void	handle_path_error(int status, t_cmd *curr, t_data *ms, t_cmd *head)
{
	if (status == 1)
	{
		permission_error(ms, *curr->cmd);
		clean_and_exit(&head, ms, 126);
	}
	else if (status == -1)
	{
		inexistant_file_error(ms, *curr->cmd);
		clean_and_exit(&head, ms, 127);
	}
}
