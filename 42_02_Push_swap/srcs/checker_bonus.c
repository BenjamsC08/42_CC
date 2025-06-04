/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:41:35 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/06 06:56:51 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_list **l)
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

char	**get_instruct(void)
{
	char	*str;
	char	*sstr;
	char	**strs;

	sstr = NULL;
	strs = NULL;
	while (42)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (!sstr)
			sstr = ft_strdup(str);
		else
			sstr = ft_strfjoin(sstr, str);
		if (ft_strlen(str) == 1)
		{
			free(str);
			break ;
		}
		free(str);
	}
	strs = ft_split(sstr, '\n');
	free(sstr);
	return (strs);
}

void	do_instruct(t_list **stack_a, t_list **stack_b, char **instruct)
{
	while (*instruct)
	{
		if (!ft_strncmp(*instruct, "ra", 3))
			rotate(stack_a, NULL, 'a');
		if (!ft_strncmp(*instruct, "rb", 3))
			rotate(stack_b, NULL, 'b');
		if (!ft_strncmp(*instruct, "rr", 3))
			rotate_both(stack_a, stack_b, 'r');
		if (!ft_strncmp(*instruct, "rra", 3))
			reverse_rotate(stack_a, NULL, 'a');
		if (!ft_strncmp(*instruct, "rrb", 3))
			reverse_rotate(stack_b, NULL, 'b');
		if (!ft_strncmp(*instruct, "rrr", 3))
			reverse_rotate_both(stack_a, stack_b, 'r');
		if (!ft_strncmp(*instruct, "pb", 3))
			push_to(stack_a, stack_b, 'b');
		if (!ft_strncmp(*instruct, "pa", 3))
			push_to(stack_a, stack_b, 'a');
		if (!ft_strncmp(*instruct, "sb", 3))
			swap(stack_b, NULL, 'b');
		if (!ft_strncmp(*instruct, "sa", 3))
			swap(stack_a, NULL, 'a');
		instruct++;
	}
}

int	checker(t_list **head)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**instruct;
	int		nb_instruct;

	instruct = get_instruct();
	if (!check_instruct(instruct))
		return (free_list(*head), free_strs(instruct), 1);
	nb_instruct = ft_strslen(instruct);
	stack_a = *head;
	stack_b = NULL;
	do_instruct(&stack_a, &stack_b, instruct);
	free_strs(instruct);
	if (stack_b)
		free_list(stack_b);
	if (is_sorted(&stack_a))
	{
		ft_printf("%sOK%s (in %d instructs)\n", GREEN, RESET, nb_instruct);
		return (free_list(*head), 0);
	}
	else
	{
		ft_printf("%sKO%s\n", RED, RESET);
		return (free_list(*head), 1);
	}
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
		return (checker(&head));
	}
	else
		return (free_strs(strs), 1);
	return (0);
}
