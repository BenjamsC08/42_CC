/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:37:28 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/27 17:57:22 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	launch_exec(t_data *ms, t_cmd **head, char *cmd_line)
{
	int	res;

	if (head)
	{
		ms->head = head;
		res = execute(ms, *head);
		if (g_sig != 130 && add_ms_history(ms, cmd_line))
			return (1);
		if (res)
			return (res);
	}
	return (0);
}

static int	command_management(char *cmd_line, t_data *ms)
{
	t_cmd	*head;
	int		res;
	t_dlist	*lex;

	ms->exit_code = 0;
	lex = NULL;
	head = NULL;
	lex = ft_lex2(ft_strdup(cmd_line), ms);
	if (!lex)
		return (ms->old_exit_code);
	ms->exit_code = ft_parsing(ms, &head, &lex);
	if (ms->exit_code)
	{
		if (add_ms_history(ms, cmd_line))
			ms->exit_code = 1;
		return (ft_free_fullstrs(&ms->cmd), free_list(&head), ms->exit_code);
	}
	res = launch_exec(ms, &head, cmd_line);
	if (res)
		return (res);
	destroy_lex(&lex);
	if (head)
		free_list(&head);
	return (ft_free_fullstrs(&ms->cmd), ms->exit_code);
}

int	ft_term(t_data *ms)
{
	char		*rl;
	static char	*color = GREEN;

	rl = NULL;
	while (42)
	{
		rl = ft_rl(color, ms);
		if (rl == NULL)
		{
			if (g_sig == 130)
				return (g_sig);
			return (ms->exit_code);
		}
		if (g_sig == 130)
		{
			g_sig = 0;
			ms->exit_code = 130;
		}
		if (rl && *rl != 0)
		{
			ms->old_exit_code = ms->exit_code;
			ms->exit_code = command_management(rl, ms);
		}
		color = colorized();
	}
}
