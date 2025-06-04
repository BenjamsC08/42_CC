/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:23:35 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/05 11:42:05 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

char			**parse_arg(char **strs);

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

// struct_help.c
t_data			*get_data(t_list *list);
t_list			*get_node_from(t_list **src, int value, char type);
void			free_move_tab(t_move **moves, int k);
t_move			**alloc_move_tab(void);
//	list_manipulation.c
void			free_list(t_list *head);
void			print_list(t_list **head);
int				is_list_decrease(t_list **stack);
int				is_list_increase(t_list **stack);
void			tab_sort(int *tab, unsigned int size);
//	list_utils.c
int				size_strs(char **strs);
int				get_max_value(t_list **stack);
int				get_min_value(t_list **stack);
int				get_index_max(t_list **stack);
int				get_index_min_value(t_list **stack);
//checker
int				check_instruct(char **instruct);

#endif
