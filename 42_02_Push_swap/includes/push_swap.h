/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:07:46 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/06 08:05:54 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gerer int min et doubons 01 1

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define REV_ROT 'r'
# define ROT 'R'
# define SWAP 'S'
# define NOT 'N'
# define VALUE 'V'
# define INDEX 'I'
# define POS 'P'
# define MIN 1
# define MAX 2

typedef struct s_data
{
	int			value;
	int			index;
	char		stack;
	int			pos;
	t_list		*prev;
}				t_data;

typedef void	(*t_move_func)(t_list **, t_list **, char);

typedef struct s_move
{
	char		type;
	char		stack;
	int			cost;
	t_move_func	op;
}				t_move;

//	push_swap_parsing.c
char			**parse_arg(char **strs);
//	push_swap_init.c
t_list			*create_elem(int nbr, int index, char stack_name);
t_list			*init_stack(char **strs);
void			update_prev(t_list **head);
//	push_swap_op.c
t_list			*update_index(t_list **curr);
void			push_to(t_list **stack_a, t_list **stack_b, char to);
void			swap(t_list **p_lst, t_list **unused, char name);
void			rotate(t_list **p_lst, t_list **unused, char name);
void			reverse_rotate(t_list **p_lst, t_list **unused, char name);
//	push_swap_op_ult.c
void			rotate_both(t_list **stack_a, t_list **stack_b, char u);
void			reverse_rotate_both(t_list **stack_a, t_list **stack_b, char u);
void			swap_both(t_list **stack_a, t_list **stack_b, char u);
//	list_manipulation.c
void			free_list(t_list *head);
void			print_list(t_list **head);
int				is_list_decrease(t_list **stack);
int				is_list_increase(t_list **stack);
//	tab_manip.c
void			tab_sort(int *tab, unsigned int size);
//	list_utils.c
int				size_strs(char **strs);
int				get_max_value(t_list **stack);
int				get_min_value(t_list **stack);
int				get_index_max(t_list **stack);
int				get_index_min_value(t_list **stack);
// push_swap_count.c
int				is_new_min_max(t_list *src, t_list **dest);
// struct_help.c
t_data			*get_data(t_list *list);
t_list			*get_node_from(t_list **src, int value, char type);
void			free_move_tab(t_move **moves, int k);
t_move			**alloc_move_tab(void);
// getter_utils.c
int				get_cost(t_move **moves);
int				get_mid(t_list **dest);
int				max_under(t_list *src, t_list **dest);
int				min_above(t_list *src, t_list **dest);
t_list			*get_target(t_list *src, t_list **dest, char targ_stack);
// count_moove.c
void			optimize_calc(t_move **all);
void			calc_unit(t_list *src, t_list **dest, t_move *move, char stack);
void			calc_cost(t_list *src, t_list **dest, t_move **moves,
					char targ_stack);
// sort_utils.c
t_list			*check_all(t_list **s_src, t_list **s_dest, int base_cost,
					char targ_stack);
void			do_moves(t_move **moves, t_list **stack_a, t_list **stack_b,
					char targ_stack);
t_move			**find_better_move(t_list **s_src, t_list **s_dest,
					char targ_stack);
void			print_move(t_move **moves, int k);

//	sort_list.c
void			inverse_list(t_list **stack_a, t_list **stack_b);
void			sort_three_last(t_list **stack_a);
void			turk_sort(t_list **stack_a, t_list **stack_b);

void			print_lists(t_list **stack_a, t_list **stack_b);

#endif
