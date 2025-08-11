/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:29:12 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/06 08:00:54 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inverse_list(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (ft_lstsize(*stack_a) > 3)
	{
		reverse_rotate(stack_a, NULL, 'a');
		push_to(stack_a, stack_b, 'b');
		i++;
	}
	swap(stack_a, NULL, 'a');
	if (ft_lstsize(*stack_a) > 2)
		reverse_rotate(stack_a, NULL, 'a');
	while (i > 0)
	{
		push_to(stack_a, stack_b, 'a');
		i--;
	}
}

void	sort_three_last(t_list **stack_a)
{
	t_data	*data_0;
	t_data	*data_1;
	t_data	*data_2;

	if (is_list_increase(stack_a))
		return ;
	data_0 = get_data(*stack_a);
	data_1 = get_data((*stack_a)->next);
	data_2 = get_data((*stack_a)->next->next);
	if (data_0->pos > data_1->pos && data_1->pos < data_2->pos
		&& data_0->pos < data_2->pos)
		swap(stack_a, NULL, 'a');
	else if (data_0->pos > data_1->pos && data_1->pos > data_2->pos)
	{
		swap(stack_a, NULL, 'a');
		reverse_rotate(stack_a, NULL, 'a');
	}
	else if (data_0->pos < data_1->pos && data_1->pos > data_2->pos)
	{
		reverse_rotate(stack_a, NULL, 'a');
		if (data_0->value == get_min_value(stack_a))
			swap(stack_a, NULL, 'a');
	}
	else if (data_0->pos > data_1->pos && data_1->pos < data_2->pos)
		rotate(stack_a, NULL, 'a');
}

int	is_sort(t_list **l)
{
	t_list	*curr;
	t_list	*next;

	curr = *l;
	next = (*l)->next;
	while (curr->next != NULL)
	{
		if ((get_data(next)->pos) < get_data(curr)->pos)
		{
			if (get_data(curr)->value == get_min_value(l)
				&& get_data(next)->value == get_max_value(l))
				continue ;
			return (0);
		}
		curr = next;
		next = curr->next;
	}
	return (1);
}

void	end_sort(t_list **stack_a)
{
	if (get_index_min_value(stack_a) < get_mid(stack_a))
	{
		while (!is_list_increase(stack_a))
			rotate(stack_a, NULL, 'a');
	}
	else
	{
		while (!is_list_increase(stack_a))
			reverse_rotate(stack_a, NULL, 'a');
	}
}

void	turk_sort(t_list **stack_a, t_list **stack_b)
{
	t_move	**moves;

	moves = NULL;
	push_to(stack_a, stack_b, 'b');
	if (ft_lstsize(*stack_a) > 3)
		push_to(stack_a, stack_b, 'b');
	while (ft_lstsize(*stack_a) > 3 && !is_sort(stack_a))
	{
		moves = find_better_move(stack_a, stack_b, 'b');
		do_moves(moves, stack_a, stack_b, 'b');
		push_to(stack_a, stack_b, 'b');
	}
	if (!is_sort(stack_a))
		sort_three_last(stack_a);
	while (ft_lstsize(*stack_b) > 0)
	{
		moves = find_better_move(stack_b, stack_a, 'a');
		do_moves(moves, stack_b, stack_a, 'a');
		push_to(stack_a, stack_b, 'a');
	}
	end_sort(stack_a);
}
