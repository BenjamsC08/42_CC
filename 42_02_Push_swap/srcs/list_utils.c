/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:08:39 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/06 07:42:53 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	get_max_value(t_list **stack)
{
	t_list	*curr;
	t_data	*data;
	int		max;

	curr = *stack;
	data = get_data(curr);
	max = data->value;
	while (curr->next)
	{
		data = get_data(curr->next);
		if (data->value > max)
			max = data->value;
		curr = curr->next;
	}
	return (max);
}

int	get_min_value(t_list **stack)
{
	t_list	*curr;
	t_data	*data;
	int		min;

	curr = *stack;
	data = get_data(curr);
	min = data->value;
	while (curr->next)
	{
		data = get_data(curr->next);
		if (data->value < min)
			min = data->value;
		curr = curr->next;
	}
	return (min);
}

int	get_index_min_value(t_list **stack)
{
	t_list	*curr;
	t_data	*data;
	int		min;

	curr = *stack;
	data = get_data(curr);
	min = get_min_value(stack);
	while (curr->next)
	{
		data = get_data(curr->next);
		if (data->value == min)
			return (data->index);
		curr = curr->next;
	}
	return (-1);
}

int	get_index_max(t_list **stack)
{
	t_list	*curr;
	t_data	*data;
	int		index;

	curr = *stack;
	data = get_data(curr);
	index = data->index;
	while (curr->next)
	{
		data = get_data(curr->next);
		if (data->index > index)
			index = data->index;
		curr = curr->next;
	}
	return (index);
}
