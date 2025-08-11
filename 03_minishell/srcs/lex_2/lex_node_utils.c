/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_node_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:56:34 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/27 00:56:40 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_token(t_dlist *lst)
{
	if (!lst || !lst->content)
		return (NULL);
	return (((t_dlex *)lst->content)->token);
}

char	get_type(t_dlist *lst)
{
	if (!lst || !lst->content)
		return (0);
	return (((t_dlex *)lst->content)->type);
}

void	del_node(void *ptr_data)
{
	t_dlex	*data;

	data = (t_dlex *)ptr_data;
	if (!data)
		return ;
	if (data->token)
	{
		free(data->token);
		data->token = NULL;
	}
	if (data)
		free(data);
	data = NULL;
}

void	destroy_lex(t_dlist **head)
{
	t_dlist	*curr;
	t_dlist	*next;

	if (!head || !*head)
		return ;
	curr = *head;
	while (curr)
	{
		next = curr->next;
		ft_dlstdelone(curr, &del_node);
		curr = next;
	}
	*head = NULL;
}

void	destroy_space_nodes(t_dlist **head)
{
	t_dlist	*curr;
	t_dlist	*next;

	curr = *head;
	while (curr)
	{
		next = curr->next;
		if (get_type(curr) == 'S')
		{
			ft_dlstdelone(curr, &del_node);
		}
		curr = next;
	}
}
