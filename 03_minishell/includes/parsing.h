/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:20:12 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 15:20:18 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

// parsing.c
int			ft_parsing(t_data *ms, t_cmd **head_parse, t_dlist **head_lex);
// parsing_extract.c
void		extract_cmd(t_data *ms, t_cmd *curr_parse, t_dlist **curr_lex);
void		extract_redir(t_data *ms, t_cmd *curr_parse, t_dlist **curr_lex);
// parsing_redir.c
int			set_redir_type(t_cmd *current, t_dlist *actual, int *type);
int			save_redir_argument(t_cmd *current, t_dlist *actual, int type);
// check_syntax.c
int			is_redir_operator(t_dlist *curr);
int			is_pipe_operator(t_dlist *curr);
int			valid_redir_syntax(t_data *ms, t_dlist *curr_lex);
int			valid_pipe_syntax(t_data *ms, t_dlist *curr_lex);
// init_list.c
t_cmd		*init_parse_node(t_data *ms, t_dlist **curr_lex);
t_cmd		*init_node(t_dlist *lex);
// list_utils.c
t_cmd		**get_head(t_cmd **current);
int			get_list_size(t_cmd *head);
void		append_parse_node(t_cmd **head, t_cmd *node);
// free_list.c
void		free_list(t_cmd **head);
void		delete_and_relink(t_dlist **curr_lex);

#endif
