/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:08:54 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/05 11:39:14 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	tab_sort(int *tab, unsigned int size)
{
	unsigned int	j;
	unsigned int	i;
	int				c;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				c = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = c;
			}
			i++;
		}
		j++;
	}
}

void	free_list(t_list *head)
{
	t_list	*current;
	t_list	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
}

void	print_list(t_list **head)
{
	t_list	*curr;
	t_data	*data;

	curr = *head;
	data = get_data(curr);
	while (data->index < (ft_lstsize(*head) - 1))
	{
		data = get_data(curr);
		if (curr == *head)
			ft_printf("list : %c, n=%d\n", data->stack, ft_lstsize(*head));
		ft_printf("index: %d\tvalue : %d\tfinal_pos: %d\n\tadd %p\n",
			data->index, data->value, data->pos, curr);
		curr = curr->next;
	}
}

int	is_list_increase(t_list **stack)
{
	t_list	*curr;
	t_data	*data_0;
	t_data	*data_1;

	curr = *stack;
	while (curr->next)
	{
		data_0 = get_data(curr);
		data_1 = get_data(curr->next);
		if (data_0->value > data_1->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_list_decrease(t_list **stack)
{
	t_list	*curr;
	t_data	*data_0;
	t_data	*data_1;

	curr = *stack;
	while (curr->next)
	{
		data_0 = get_data(curr);
		data_1 = get_data(curr->next);
		if (data_0->value < data_1->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}
