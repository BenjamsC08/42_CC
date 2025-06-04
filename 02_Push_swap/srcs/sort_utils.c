/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 07:39:50 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/06 07:43:05 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	other_alloc(t_list *curr, t_list **s_dest, char stack)
{
	t_move	**moves_t;
	int		cost;

	cost = INT_MAX;
	moves_t = alloc_move_tab();
	if (!moves_t)
		return (cost);
	calc_cost(curr, s_dest, moves_t, stack);
	cost = get_cost(moves_t);
	free_move_tab(moves_t, 3);
	return (cost);
}

t_list	*check_all(t_list **s_src, t_list **s_dest, int base_cost,
		char targ_stack)
{
	int		cost;
	int		min;
	t_list	*curr;
	t_list	*n_out;

	min = INT_MAX;
	curr = (*s_src)->next;
	n_out = NULL;
	while (curr)
	{
		cost = other_alloc(curr, s_dest, targ_stack);
		if (cost < base_cost)
		{
			if (cost <= 3)
				return (curr);
			if (cost < min)
			{
				n_out = curr;
				min = cost;
			}
		}
		curr = curr->next;
	}
	return (n_out);
}

void	do_moves(t_move **moves, t_list **stack_s, t_list **stack_d,
		char targ_stack)
{
	int		i;
	char	src_stack;

	i = -1;
	if (targ_stack == 'b')
		src_stack = 'a';
	else
		src_stack = 'b';
	while ((++i) < moves[0]->cost)
		moves[0]->op(stack_s, stack_d, src_stack);
	i = -1;
	while ((++i) < moves[1]->cost)
		moves[1]->op(stack_d, stack_s, targ_stack);
	i = -1;
	while ((++i) < moves[2]->cost)
		moves[2]->op(stack_s, stack_d, 'r');
	free_move_tab(moves, 3);
	moves = NULL;
}

t_move	**find_better_move(t_list **s_src, t_list **s_dest, char targ_stack)
{
	int		base_cost;
	t_list	*best;
	t_move	**moves;

	moves = alloc_move_tab();
	if (!moves)
		return (NULL);
	calc_cost(*s_src, s_dest, moves, targ_stack);
	base_cost = get_cost(moves);
	if (base_cost <= 3)
		return (moves);
	best = check_all(s_src, s_dest, base_cost, targ_stack);
	if (!best || best == *s_src)
		return (moves);
	free_move_tab(moves, 3);
	moves = alloc_move_tab();
	if (!moves)
		return (NULL);
	calc_cost(best, s_dest, moves, targ_stack);
	return (moves);
}
