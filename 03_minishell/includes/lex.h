/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:56:11 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/27 17:25:21 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# include "minishell.h"

// is_arg_ok.c
int		export_arg_check(t_data *minishell, char *str);
// expandable.c

char	*expand_env_var(char *rl, t_data *minishell);
// lex_utils.c
int		skip_whitespace(char **str);
char	*skip_whitespace_del_tab(char **str);
char	*get_str_status(char **str, t_data *data);
// lex_node_utils.c
char	*get_token(t_dlist *lst);
char	get_type(t_dlist *lst);
void	del_node(void *lst);
void	destroy_space_nodes(t_dlist **head);
void	destroy_lex(t_dlist **head);
// lex_func_utils.c
void	print_lex(t_dlist **head);
t_dlist	*explode_rl(char *rl);
void	condition_explode(char **rl, char type, t_dlist **head);
// lex
void	add_node(char *src, char type, t_dlist **head);
t_dlist	*ft_lex2(char *rl, t_data *minishell);

#endif
