/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:37:11 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 11:55:19 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_redir_in_type(t_dlist *actual, t_cmd *current, int *type)
{
	if (!ft_strcmp(get_token(actual), "<<"))
	{
		current->type_redir_in = HEREDOC;
		*type = 0;
	}
	else if (!ft_strcmp(get_token(actual), "<"))
	{
		current->type_redir_in = INFILE;
		*type = 0;
	}
}

int	set_redir_type(t_cmd *current, t_dlist *actual, int *type)
{
	int	i;

	if (!ft_strcmp(get_token(actual), "<<")
		|| !ft_strcmp(get_token(actual), "<"))
		handle_redir_in_type(actual, current, type);
	else
	{
		i = -1;
		while (current->type_redir_out[++i] != -1)
			;
		if (!ft_strcmp(get_token(actual), ">>"))
		{
			current->type_redir_out[i] = APPEND;
			*type = 1;
		}
		else if (!ft_strcmp(get_token(actual), ">"))
		{
			current->type_redir_out[i] = TRUNC;
			*type = 1;
		}
	}
	return (0);
}

static char	**append_redir(char **redir_list, char *arg)
{
	int		i;
	int		j;
	char	**new_list;

	i = ft_strslen(redir_list);
	j = -1;
	new_list = NULL;
	if (!redir_list)
		return (NULL);
	if (!arg)
		return (ft_free_fullstrs(&redir_list), NULL);
	new_list = ft_calloc(i + 2, sizeof(char *));
	if (!new_list)
		return (ft_free_fullstrs(&redir_list), NULL);
	while (redir_list[++j])
	{
		new_list[j] = ft_strdup(redir_list[j]);
		if (!new_list[j])
			return (ft_free_fullstrs(&redir_list), NULL);
	}
	new_list[i] = ft_strdup(arg);
	if (!new_list[i])
		return (ft_free_fullstrs(&redir_list), NULL);
	ft_free_fullstrs(&redir_list);
	return (new_list);
}

static int	save_redir_in_argument(t_cmd *current, t_dlist *actual, int type)
{
	if (!type && current->type_redir_in == INFILE)
	{
		if (!current->redir_in)
			current->redir_in = ft_calloc(1, sizeof(char *));
		current->redir_in = append_redir(current->redir_in,
				get_token(actual->next));
		if (!current->redir_in)
			return (0);
	}
	else if (!type && current->type_redir_in == HEREDOC)
	{
		if (!current->hd || !current->hd[0])
			current->hd = ft_calloc(1, sizeof(char *));
		current->hd = append_redir(current->hd, get_token(actual->next));
		if (!current->hd)
			return (0);
	}
	return (1);
}

int	save_redir_argument(t_cmd *current, t_dlist *actual, int type)
{
	if (!save_redir_in_argument(current, actual, type))
		return (1);
	if (type)
	{
		if (!current->redir_out)
			current->redir_out = ft_calloc(1, sizeof(char *));
		current->redir_out = append_redir(current->redir_out,
				get_token(actual->next));
		if (!current->redir_out)
			return (1);
	}
	return (0);
}
