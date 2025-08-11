/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:37:52 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 11:54:05 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	extract_cmd(t_data *ms, t_cmd *curr_parse, t_dlist **curr_lex)
{
	while (get_type(*curr_lex) == 'W')
	{
		if (!curr_parse->cmd)
		{
			curr_parse->cmd = ft_calloc(2, sizeof(char *));
			if (!alloc_check(curr_parse->cmd, ms))
				return ;
			curr_parse->cmd[0] = ft_strdup(get_token(*curr_lex));
			if (!alloc_check(curr_parse->cmd[0], ms))
			{
				ft_free_fullstrs(&curr_parse->cmd);
				return ;
			}
		}
		else
		{
			curr_parse->cmd = ft_strsfjoin(curr_parse->cmd,
					get_token(*curr_lex));
			if (!alloc_check(curr_parse->cmd, ms))
				return ;
		}
		delete_and_relink(curr_lex);
	}
}

void	extract_redir(t_data *ms, t_cmd *curr_parse, t_dlist **curr_lex)
{
	int	type;

	if (!valid_redir_syntax(ms, *curr_lex))
		return ;
	type = 0;
	if (set_redir_type(curr_parse, *curr_lex, &type)
		|| save_redir_argument(curr_parse, *curr_lex, type))
	{
		ms->exit_code = 1;
		return ;
	}
	delete_and_relink(curr_lex);
	delete_and_relink(curr_lex);
}
