/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:28:26 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/06 07:42:45 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_calc(t_move **all)
{
	if (all[0]->type != all[1]->type || all[0]->cost == 0 || all[1]->cost == 0)
	{
		all[2]->stack = 'L';
		all[2]->type = 'L';
		all[2]->cost = 0;
		all[2]->op = NULL;
		return ;
	}
	all[2]->type = all[0]->type;
	if (all[2]->type == ROT)
		all[2]->op = rotate_both;
	else
		all[2]->op = reverse_rotate_both;
	all[2]->cost = ft_min(all[0]->cost, all[1]->cost);
	all[1]->cost -= all[2]->cost;
	all[0]->cost -= all[2]->cost;
	all[2]->stack = 'W';
}

void	calc_unit(t_list *src, t_list **dest, t_move *move, char stack)
{
	if (src == *dest)
		move->cost = ((get_data(src))->index);
	else
		move->cost = ((get_data(get_target(src, dest, stack)))->index);
	if (move->cost > get_mid(dest))
	{
		move->cost = ft_abs((get_index_max(dest) + 1) - move->cost);
		move->type = REV_ROT;
		move->op = reverse_rotate;
	}
	else
	{
		move->type = ROT;
		move->op = rotate;
	}
	move->stack = stack;
}

void	calc_cost(t_list *src, t_list **dest, t_move **moves, char targ_stack)
{
	char	s_stack;

	if (targ_stack == 'a')
		s_stack = 'b';
	else
		s_stack = 'a';
	calc_unit(src, &src, moves[0], s_stack);
	calc_unit(src, dest, moves[1], targ_stack);
	moves[1]->stack = targ_stack;
	optimize_calc(moves);
}
