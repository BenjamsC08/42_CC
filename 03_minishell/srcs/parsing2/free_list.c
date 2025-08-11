/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:15:13 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 11:17:27 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_node(t_cmd *node)
{
	if (!node)
		return ;
	if (node->cmd)
		ft_free_fullstrs(&node->cmd);
	if (node->hd)
		ft_free_fullstrs(&node->hd);
	if (node->redir_in)
		ft_free_fullstrs(&node->redir_in);
	if (node->redir_out)
		ft_free_fullstrs(&node->redir_out);
	if (node->infile != -1)
	{
		close(node->infile);
		node->infile = -1;
	}
	if (node->outfile != -1)
	{
		close(node->outfile);
		node->outfile = -1;
	}
	if (node->type_redir_out)
		free(node->type_redir_out);
	node->next = NULL;
}

void	free_list(t_cmd **head)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		free_node(current);
		free(current);
		current = next;
	}
	*head = NULL;
}

void	delete_and_relink(t_dlist **curr_lex)
{
	if (!curr_lex || !*curr_lex)
		return ;
	if ((*curr_lex)->next)
	{
		*curr_lex = (*curr_lex)->next;
		ft_dlstdelone((*curr_lex)->prev, &del_node);
	}
	else
	{
		ft_dlstdelone(*curr_lex, &del_node);
		*curr_lex = NULL;
	}
}
