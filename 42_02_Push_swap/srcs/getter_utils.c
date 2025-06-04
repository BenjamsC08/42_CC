/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 07:37:33 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/06 07:42:49 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cost(t_move **moves)
{
	int	cost;

	cost = 0;
	cost += moves[0]->cost;
	cost += moves[1]->cost;
	cost += moves[2]->cost;
	return (cost + 1);
}

int	get_mid(t_list **dest)
{
	int	size;

	size = ft_lstsize(*dest);
	if (size % 2 == 1)
		size += 1;
	return (size >> 1);
}

int	max_under(t_list *src, t_list **dest)
{
	int		pos_s;
	int		out;
	t_list	*curr;
	t_data	*data;

	pos_s = get_data(src)->pos;
	curr = *dest;
	out = get_min_value(dest);
	while (curr)
	{
		data = get_data(curr);
		if (data->pos < pos_s && data->value > out)
			out = data->value;
		curr = curr->next;
	}
	return (out);
}

int	min_above(t_list *src, t_list **dest)
{
	int		pos_s;
	int		out;
	t_list	*curr;
	t_data	*data;

	pos_s = get_data(src)->pos;
	curr = *dest;
	out = get_max_value(dest);
	while (curr)
	{
		data = get_data(curr);
		if (data->pos > pos_s && data->value < out)
			out = data->value;
		curr = curr->next;
	}
	return (out);
}

t_list	*get_target(t_list *src, t_list **dest, char targ_stack)
{
	if (targ_stack == 'a')
	{
		if (is_new_min_max(src, dest))
			return (get_node_from(dest, get_min_value(dest), VALUE));
		return (get_node_from(dest, min_above(src, dest), VALUE));
	}
	else
	{
		if (is_new_min_max(src, dest))
			return (get_node_from(dest, get_max_value(dest), VALUE));
		return (get_node_from(dest, max_under(src, dest), VALUE));
	}
}
