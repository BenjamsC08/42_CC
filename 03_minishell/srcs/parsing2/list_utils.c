/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:08:31 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 11:51:15 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	**get_head(t_cmd **current)
{
	t_cmd	**head;

	head = current;
	if (!current)
		return (NULL);
	while ((*head)->prev != NULL)
		*head = (*head)->prev;
	return (head);
}

int	get_list_size(t_cmd *head)
{
	t_cmd	*current;
	int		i;

	if (!head)
		return (0);
	current = head;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

static void	append_back_node(t_cmd **head, t_cmd *new)
{
	t_cmd	*current;

	current = *head;
	while (current)
	{
		if (current->next == NULL)
		{
			current->next = new;
			new->prev = current;
			return ;
		}
		current = current->next;
	}
}

void	append_parse_node(t_cmd **head, t_cmd *node)
{
	if (!*head)
		*head = node;
	else
		append_back_node(head, node);
}
