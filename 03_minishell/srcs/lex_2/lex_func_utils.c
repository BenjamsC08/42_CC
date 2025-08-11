/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_func_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:56:12 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/27 00:56:42 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*explode_rl(char *rl)
{
	t_dlist	*head;
	char	type;

	head = NULL;
	while (*rl)
	{
		type = 'W';
		condition_explode(&rl, type, &head);
	}
	return (head);
}

void	condition_explode(char **rl, char type, t_dlist **head)
{
	char	*temp;

	if (**rl == 34 || **rl == 39)
		temp = ft_strdup_to(rl, **rl);
	else if (ft_is_in(**rl, "<>|"))
	{
		temp = ft_strdup_only(rl, **rl);
		type = 'O';
	}
	else if (**rl != 32)
		temp = ft_strdup_to_charset(rl, " <>|'\"");
	else
	{
		temp = ft_strdup(" ");
		(*rl)++;
		type = 'S';
	}
	if (temp)
	{
		add_node(temp, type, head);
		free(temp);
	}
	temp = NULL;
}
