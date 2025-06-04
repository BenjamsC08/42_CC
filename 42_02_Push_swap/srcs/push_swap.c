/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:51:30 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/06 07:44:48 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **head)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (is_list_increase(head))
		return ;
	if (ft_lstsize(*head) == 2)
		return (swap(head, NULL, 'a'));
	if (ft_lstsize(*head) == 3)
		return (sort_three_last(head), free(*head));
	stack_a = *head;
	stack_b = NULL;
	turk_sort(&stack_a, &stack_b);
	free_list(stack_a);
	if (stack_b)
		free_list(stack_b);
}

int	main(int argc, char **argv)
{
	char	**strs;
	t_list	*head;

	strs = NULL;
	if (argc == 2)
		strs = ft_split(argv[1], ' ');
	else if (argc > 2)
		strs = ft_strsdup(++argv);
	else
		return (free_strs(strs), 1);
	strs = parse_arg(strs);
	if (strs)
	{
		head = init_stack(strs);
		free_strs(strs);
		if (!head)
			return (free_list(head), 1);
		push_swap(&head);
	}
	else
		return (free_strs(strs), 1);
	return (0);
}
