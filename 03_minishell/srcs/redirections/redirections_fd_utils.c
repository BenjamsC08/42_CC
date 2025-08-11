/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_fd_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 07:28:51 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 13:13:20 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	start_redirections_fds(t_cmd *current, t_data *minishell)
{
	if (current->infile != -1)
	{
		if (dup2(current->infile, STDIN_FILENO) == -1)
		{
			fd_error("can't read from infile", minishell);
			return (minishell->exit_code = 1);
		}
		close(current->infile);
	}
	if (current->outfile != -1)
	{
		if (dup2(current->outfile, STDOUT_FILENO) == -1)
		{
			fd_error("can't write in outfile", minishell);
			return (minishell->exit_code = 1);
		}
		close(current->outfile);
	}
	return (0);
}

int	reset_redirections_fds(t_data *minishell)
{
	if (minishell->stdin != -1)
	{
		if (dup2(minishell->stdin, STDIN_FILENO) == -1)
			return (fd_error("can't reset STDIN", minishell), 1);
	}
	if (minishell->stdout != -1)
	{
		if (dup2(minishell->stdout, STDOUT_FILENO) == -1)
			return (fd_error("can't reset STDOUT", minishell), 1);
	}
	return (0);
}
