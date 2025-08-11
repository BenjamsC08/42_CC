/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_help_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:28:50 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/05 11:39:08 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_data	*get_data(t_list *list)
{
	t_data	*data;

	data = (t_data *)list->content;
	return (data);
}

t_list	*get_node_from(t_list **src, int value, char type)
{
	t_data	*data;
	t_list	*curr;

	curr = *src;
	while (curr)
	{
		data = get_data(curr);
		if (type == INDEX && data->index == value)
			return (curr);
		if (type == VALUE && data->value == value)
			return (curr);
		if (type == POS && data->pos == value)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void	free_move_tab(t_move **moves, int k)
{
	int	i;

	i = -1;
	if (k == 0)
		k = 3;
	while (++i < k)
	{
		if (moves[i])
			free(moves[i]);
	}
	free(moves);
	return ;
}

t_move	**alloc_move_tab(void)
{
	t_move	**dup;
	int		i;

	dup = (t_move **)malloc(sizeof(t_move *) * 3);
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < 3)
	{
		dup[i] = (t_move *)malloc(sizeof(t_move));
		if (!dup[i])
			return (free_move_tab(dup, i), NULL);
	}
	return (dup);
}

int	is_new_min_max(t_list *src, t_list **dest)
{
	int	new_val;
	int	tmp;

	new_val = ((t_data *)src->content)->value;
	tmp = get_min_value(dest);
	if (new_val < tmp)
		return (MIN);
	tmp = get_max_value(dest);
	if (new_val > tmp)
		return (MAX);
	return (0);
}
