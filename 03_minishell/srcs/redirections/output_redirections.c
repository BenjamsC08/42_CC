/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:40:33 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 13:17:00 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	outfiles_loop(t_data *minishell, t_cmd *curr, int *fd)
{
	int	i;

	i = -1;
	while (curr->redir_out[++i])
	{
		if (*fd != -1)
			close(*fd);
		if (curr->type_redir_out[i] == APPEND)
			*fd = open(curr->redir_out[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (curr->type_redir_out[i] == TRUNC)
			*fd = open(curr->redir_out[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		curr->outfile = *fd;
		if (*fd == -1)
		{
			if (errno == EMFILE || errno == ENFILE)
				fd_error("outfiles_loop", minishell);
			outfile_error(minishell, curr->redir_out[i]);
			minishell->exit_code = 1;
			ft_free_strs(curr->redir_out);
			free(curr->type_redir_out);
			if (curr->outfile != -1)
				close (curr->outfile);
			return (curr->type_redir_out = NULL, ft_free_strs(curr->cmd));
		}
	}
}

int	output_redirections(t_data *minishell, t_cmd *head)
{
	t_cmd	*current;
	int		fd;

	if (!head)
		return (1);
	current = head;
	while (current)
	{
		if (current->redir_out)
		{
			fd = -1;
			minishell->exit_code = 0;
			outfiles_loop(minishell, current, &fd);
		}
		current = current->next;
	}
	return (0);
}
