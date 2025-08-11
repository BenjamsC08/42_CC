/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:40:07 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/06 07:43:00 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*update_index(t_list **curr)
{
	t_list	*next;
	int		i;

	next = *curr;
	i = 0;
	while (next)
	{
		((t_data *)next->content)->index = i++;
		next = next->next;
	}
	return (*curr);
}

void	push_to(t_list **stack_a, t_list **stack_b, char to)
{
	t_list	*top;

	if (*stack_a && to == 'b')
	{
		top = *stack_a;
		*stack_a = update_index(&top->next);
		top->next = NULL;
		((t_data *)top->content)->stack = to;
		ft_lstadd_front(stack_b, top);
		*stack_b = update_index(stack_b);
	}
	else if (*stack_b && to == 'a')
	{
		top = *stack_b;
		*stack_b = update_index(&top->next);
		top->next = NULL;
		((t_data *)top->content)->stack = to;
		ft_lstadd_front(stack_a, top);
		*stack_a = update_index(stack_a);
	}
	update_prev(stack_a);
	update_prev(stack_b);
	ft_printf("p%c\n", to);
}

void	swap(t_list **p_lst, t_list **unused, char name)
{
	t_list	*lst;
	t_list	*next;

	(void)unused;
	lst = *p_lst;
	if (lst->next == NULL)
		return ;
	next = lst->next;
	lst->next = next->next;
	next->next = lst;
	*p_lst = next;
	update_index(p_lst);
	update_prev(p_lst);
	if (name != 's')
		ft_printf("s%c\n", name);
}

void	rotate(t_list **p_lst, t_list **unused, char name)
{
	t_list	*lst;
	t_list	*last;

	(void)unused;
	lst = *p_lst;
	if (lst->next == NULL)
		return ;
	last = ft_lstlast(*p_lst);
	*p_lst = lst->next;
	lst->next = NULL;
	last->next = lst;
	update_index(p_lst);
	update_prev(p_lst);
	if (name != 'r')
		ft_printf("r%c\n", name);
}

void	reverse_rotate(t_list **p_lst, t_list **unused, char name)
{
	t_list	*lst;
	t_list	*last;
	t_list	*p_last;

	(void)unused;
	lst = *p_lst;
	if (lst->next == NULL)
		return ;
	last = ft_lstlast(*p_lst);
	p_last = ft_lstpenultimate(*p_lst);
	last->next = lst;
	p_last->next = NULL;
	*p_lst = last;
	update_index(p_lst);
	update_prev(p_lst);
	if (name != 'r')
		ft_printf("rr%c\n", name);
}
