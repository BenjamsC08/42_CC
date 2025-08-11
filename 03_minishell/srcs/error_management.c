/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:44:27 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/27 17:21:01 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_not_found(t_data *ms, char *cmd)
{
	ft_fprintf(2, "%s: %s: command not found\n", ms->name, cmd);
}

void	syntax_error(t_data *ms, char *s)
{
	ft_fprintf(2, "%s: syntax error near unexpected token `%s'\n", ms->name, s);
}

void	inexistant_file_error(t_data *ms, char *s)
{
	ft_fprintf(2, "%s: %s: No such file or directory\n", ms->name, s);
}

void	permission_error(t_data *ms, char *s)
{
	ft_fprintf(2, "%s: %s: Permission denied\n", ms->name, s);
}

void	outfile_error(t_data *ms, char *s)
{
	ft_fprintf(2, "%s: %s: %s\n", ms->name, s, strerror(errno));
}
