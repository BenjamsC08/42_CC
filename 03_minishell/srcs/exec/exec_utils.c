/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:04:44 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 15:38:38 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_and_exit(t_cmd **head, t_data *ms, int code)
{
	free_list(head);
	destroy_data(ms);
	exit(code);
}

void	reset_std_fd(t_data *ms)
{
	close_and_reassign_fd(&ms->stdin);
	close_and_reassign_fd(&ms->stdout);
}

void	check_env_size(t_data *ms, t_cmd **head, t_cmd *curr)
{
	if (ms->env_size > ARG_MAX)
	{
		ft_fprintf(2, "%s: %s: Argument list too long\n", ms->name, *curr->cmd);
		free_list(head);
		destroy_data(ms);
		exit(126);
	}
}

void	cleanup_pipes(t_data *ms)
{
	close_and_reassign_fd(&ms->pipes[0]);
	close_and_reassign_fd(&ms->pipes[1]);
}

int	handle_pipe_error(t_data *ms, const char *location)
{
	if (errno == EMFILE || errno == ENFILE)
		fd_error((char *)location, ms);
	ms->exit_code = 1;
	return (ms->exit_code);
}
