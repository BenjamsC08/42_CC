/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:16:23 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 13:38:59 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	verify_rights(t_data *minishell, t_cmd *current, int *fd, int i)
{
	errno = 0;
	if (access(current->redir_in[i], R_OK) == 0)
	{
		if (current->type_redir_in == INFILE && *fd != -1)
			close(*fd);
		*fd = open(current->redir_in[i], O_RDONLY);
		if (*fd == -1)
			return (0);
		if (current->type_redir_in == INFILE && *fd != -1)
		{
			current->infile = *fd;
			minishell->exit_code = 0;
		}
		if (current->type_redir_in != INFILE && *fd != -1)
			close(*fd);
	}
	else
		return (0);
	return (1);
}

static int	handle_infile_rights(t_data *ms, t_cmd *curr, int *fd, int i)
{
	if (access(curr->redir_in[i], F_OK) != 0)
	{
		inexistant_file_error(ms, curr->redir_in[i]);
		ms->exit_code = 1;
		return (0);
	}
	if (!verify_rights(ms, curr, fd, i))
	{
		if (errno == EMFILE || errno == ENFILE)
			fd_error("can't read from infile", ms);
		else
			permission_error(ms, curr->redir_in[i]);
		ms->exit_code = 1;
		return (0);
	}
	return (1);
}

static void	infiles_test_loop(t_data *minishell, t_cmd *current)
{
	int	i;
	int	fd;

	i = -1;
	fd = -1;
	while (current->redir_in[++i])
	{
		if (!handle_infile_rights(minishell, current, &fd, i))
			break ;
	}
}

int	infile_redirections(t_data *minishell, t_cmd *head)
{
	t_cmd	*current;

	if (!head)
		return (minishell->exit_code = 1);
	current = head;
	while (current)
	{
		if (current->redir_in)
			infiles_test_loop(minishell, current);
		current = current->next;
	}
	return (minishell->exit_code);
}
