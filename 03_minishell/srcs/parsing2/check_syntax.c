/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:25:13 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 11:50:04 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir_operator(t_dlist *curr)
{
	if (!curr)
		return (ERROR_REDIR);
	if (get_type(curr) != 'O')
		return (NOT_REDIR);
	if (!ft_strcmp(get_token(curr), "<<"))
		return (IS_REDIR);
	else if (!ft_strcmp(get_token(curr), "<"))
		return (IS_REDIR);
	else if (!ft_strcmp(get_token(curr), ">>"))
		return (IS_REDIR);
	else if (!ft_strcmp(get_token(curr), ">"))
		return (IS_REDIR);
	return (NOT_REDIR);
}

int	is_pipe_operator(t_dlist *curr)
{
	if (get_type(curr) == 'O' && !ft_strcmp(get_token(curr), "|"))
		return (1);
	return (0);
}

int	valid_redir_syntax(t_data *ms, t_dlist *curr_lex)
{
	if (curr_lex->next == NULL || get_type(curr_lex->next) == 'O')
	{
		if (curr_lex->next == NULL)
			syntax_error(ms, "newline");
		else if (get_type(curr_lex->next) == 'O')
			syntax_error(ms, get_token(curr_lex->next));
		ms->exit_code = 2;
		return (0);
	}
	return (1);
}

int	valid_pipe_syntax(t_data *ms, t_dlist *curr_lex)
{
	if (!curr_lex)
		return (0);
	if (curr_lex->next == NULL || is_pipe_operator(curr_lex->next))
	{
		syntax_error(ms, "|");
		ms->exit_code = 2;
		return (0);
	}
	return (1);
}
