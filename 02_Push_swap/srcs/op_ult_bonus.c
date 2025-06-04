/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ult_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:46:40 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/06 06:52:08 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_both(t_list **stack_a, t_list **stack_b, char u)
{
	(void)u;
	rotate(stack_a, NULL, 'r');
	rotate(stack_b, NULL, 'r');
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b, char u)
{
	(void)u;
	reverse_rotate(stack_a, NULL, 'r');
	reverse_rotate(stack_b, NULL, 'r');
}

void	swap_both(t_list **stack_a, t_list **stack_b, char u)
{
	(void)u;
	swap(stack_a, NULL, 'r');
	swap(stack_b, NULL, 'r');
}
