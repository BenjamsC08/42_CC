/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:56:16 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/28 05:46:27 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dlex	*structuring(char *str, char type)
{
	t_dlex	*data;

	data = ft_calloc(1, sizeof(t_dlex));
	if (!data)
		return (NULL);
	data->token = ft_strdup(str);
	if (!data->token)
		return (free(data), NULL);
	data->type = type;
	return (data);
}

void	add_node(char *src, char type, t_dlist **head)
{
	t_dlex	*data;
	t_dlist	*lst;

	lst = NULL;
	data = NULL;
	if (src && type)
		data = structuring(src, type);
	if (!data)
		return ;
	if (!*head)
	{
		if (!head)
			return (del_node(data));
		*head = ft_dlstnew(data);
		return ;
	}
	lst = ft_dlstnew(data);
	if (!lst)
		return (free(data));
	ft_dlstadd_back(head, lst);
}

void	merge_loop(t_dlist **curr, t_dlist **next, t_dlist **head)
{
	char	*str;

	while (*next && get_type(*next) == 'W')
	{
		str = ft_strfjoin(get_token(*curr), get_token(*next));
		if (!str)
			return (destroy_lex(head));
		((t_dlex *)(*curr)->content)->token = str;
		if ((*next)->next)
		{
			(*curr)->next = (*next)->next;
			(*curr)->next->prev = (*curr);
		}
		else
			(*curr)->next = NULL;
		ft_dlstdelone(*next, &del_node);
		(*next) = (*curr)->next;
	}
}

static void	merge_node(t_dlist **head)
{
	t_dlist	*curr;
	t_dlist	*next;

	curr = *head;
	while (curr)
	{
		if (!curr->next)
			break ;
		next = curr->next;
		if (get_type(curr) == 'W' && get_type(next) == 'W')
			merge_loop(&curr, &next, head);
		curr = next;
	}
}

t_dlist	*ft_lex2(char *rl, t_data *minishell)
{
	t_dlist	*lex;

	if (!rl)
		return (NULL);
	lex = NULL;
	rl = skip_whitespace_del_tab(&rl);
	rl = expand_env_var(rl, minishell);
	if (!rl)
		return (NULL);
	lex = explode_rl(rl);
	if (lex)
		merge_node(&lex);
	destroy_space_nodes(&lex);
	return (free(rl), lex);
}
