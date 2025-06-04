/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:43:33 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/05 11:38:54 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*create_elem(int nbr, int index, char stack_name)
{
	t_list	*new;
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->value = nbr;
	data->index = index;
	data->stack = stack_name;
	data->pos = 0;
	data->prev = NULL;
	new = ft_lstnew(data);
	if (!new)
		return (free(data), NULL);
	return (new);
}

static void	set_pos(t_list **head, int *tab)
{
	t_list	*curr;
	t_data	*data;
	int		i;

	curr = *head;
	i = 0;
	while (curr)
	{
		data = get_data(curr);
		if (data->value != tab[i])
			i++;
		else
		{
			data->pos = i;
			curr = curr->next;
			i = 0;
		}
	}
}

static t_list	*get_pos(t_list **head)
{
	int		*tab;
	t_list	*curr;
	t_data	*data;
	int		i;

	curr = ft_lstlast(*head);
	data = get_data(curr);
	tab = (int *)malloc(sizeof(int) * (data->index + 1));
	curr = *head;
	i = 0;
	while (curr)
	{
		data = get_data(curr);
		tab[i++] = data->value;
		curr = curr->next;
	}
	tab_sort(tab, (data->index + 1));
	set_pos(head, tab);
	free(tab);
	return (*head);
}

t_list	*init_stack(char **strs)
{
	t_list		*head;
	t_list		*curr;
	t_list		*new;
	int			i;
	const int	strs_l = size_strs(strs);

	head = NULL;
	curr = NULL;
	i = -1;
	while ((++i) < strs_l)
	{
		new = create_elem(ft_atoi(strs[i]), i, 'a');
		if (!new)
			return (free_list(head), NULL);
		if (head == NULL)
			head = new;
		else
			curr->next = new;
		curr = new;
	}
	head = get_pos(&head);
	update_prev(&head);
	return (head);
}

void	update_prev(t_list **head)
{
	t_list	*curr;
	t_data	*data;

	if (!*head)
		return ;
	curr = *head;
	while (curr->next)
	{
		data = get_data(curr->next);
		data->prev = curr;
		curr = curr->next;
	}
	data = get_data(*head);
	data->prev = curr;
}
