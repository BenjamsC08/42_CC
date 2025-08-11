/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:25:21 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 11:52:13 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_parse_node(t_data *ms, t_dlist **curr_lex)
{
	t_cmd	*node;

	node = init_node(*curr_lex);
	if (!node)
		ms->exit_code = 1;
	return (node);
}

static int	count_redir_out(t_dlist *lex)
{
	t_dlist	*curr;
	int		count;

	curr = lex;
	count = 0;
	while (curr && !is_pipe_operator(curr))
	{
		if (get_type(curr) == 'O')
		{
			if (!ft_strcmp(get_token(curr), ">>")
				|| !ft_strcmp(get_token(curr), ">"))
				count++;
		}
		curr = curr->next;
	}
	return (count);
}

static int	*calloc_filled_with_minus_one(int nb)
{
	int	*dst;
	int	i;

	if (nb <= 0)
		return (NULL);
	dst = ft_calloc(nb, sizeof(int));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < nb)
		dst[i] = -1;
	return (dst);
}

t_cmd	*init_node(t_dlist *lex)
{
	static int		no = 0;
	t_cmd			*node;
	int				n_redir_out;

	n_redir_out = count_redir_out(lex);
	node = ft_calloc(1, sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->no = no;
	node->pipe = FALSE;
	node->infile = -1;
	node->outfile = -1;
	node->type_redir_in = -1;
	node->type_redir_out = calloc_filled_with_minus_one(n_redir_out);
	if (!node->type_redir_out && n_redir_out > 0)
	{
		if (node)
			free(node);
		node = NULL;
	}
	no++;
	return (node);
}
