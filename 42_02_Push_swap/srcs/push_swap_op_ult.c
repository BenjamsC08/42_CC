/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_ult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 03:03:52 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/06 07:43:02 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_list **stack_a, t_list **stack_b, char u)
{
	(void)u;
	rotate(stack_a, NULL, 'r');
	rotate(stack_b, NULL, 'r');
	ft_printf("rr\n");
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b, char u)
{
	(void)u;
	reverse_rotate(stack_a, NULL, 'r');
	reverse_rotate(stack_b, NULL, 'r');
	ft_printf("rrr\n");
}

void	swap_both(t_list **stack_a, t_list **stack_b, char u)
{
	(void)u;
	swap(stack_a, NULL, 'r');
	swap(stack_b, NULL, 'r');
	ft_printf("ss\n");
}
