/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:16:35 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 15:39:55 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	process_tokens(t_data *ms, t_cmd *node, t_dlist **curr_lex)
{
	while (*curr_lex && !is_pipe_operator(*curr_lex))
	{
		if (is_redir_operator(*curr_lex))
			extract_redir(ms, node, curr_lex);
		else if (get_type(*curr_lex) == 'W')
			extract_cmd(ms, node, curr_lex);
		else
		{
			syntax_error(ms, get_token(*curr_lex));
			delete_and_relink(curr_lex);
			ms->exit_code = 2;
			return (1);
		}
		if (ms->exit_code)
			return (0);
	}
	return (1);
}

static int	handle_pipe_token(t_data *ms, t_cmd *node, t_dlist **curr_lex)
{
	if (*curr_lex && is_pipe_operator(*curr_lex))
	{
		if (!node->cmd)
			return (syntax_error(ms, "|"), ms->exit_code = 2, 0);
		if (!valid_pipe_syntax(ms, *curr_lex))
			return (0);
		node->pipe = TRUE;
		delete_and_relink(curr_lex);
	}
	return (1);
}

static void	build_node(t_data *ms, t_cmd **head_parse, t_dlist **lex)
{
	t_dlist	*curr_lex;
	t_cmd	*curr_node;

	curr_lex = *lex;
	curr_node = init_parse_node(ms, &curr_lex);
	if (!curr_node)
	{
		*lex = curr_lex;
		return ;
	}
	append_parse_node(head_parse, curr_node);
	if (!process_tokens(ms, curr_node, &curr_lex))
	{
		*lex = curr_lex;
		return ;
	}
	if (!handle_pipe_token(ms, curr_node, &curr_lex))
	{
		*lex = curr_lex;
		return ;
	}
	*lex = curr_lex;
}

int	ft_parsing(t_data *ms, t_cmd **head_parse, t_dlist **head_lex)
{
	t_dlist	*curr_lex;

	curr_lex = *head_lex;
	while (curr_lex)
	{
		build_node(ms, head_parse, &curr_lex);
		if (ms->exit_code)
			break ;
	}
	*head_lex = curr_lex;
	destroy_lex(head_lex);
	return (ms->exit_code);
}
