/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myexec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:18:57 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 15:19:41 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYEXEC_H
# define MYEXEC_H

# include "minishell.h"

// command_path_utils.c
int			find_cmd_path(char **cmd, t_data *minishell, char **envp);
// heredoc.c
void		heredoc_prompt_fd(t_data *minishell);
int			*open_heredoc_pipe(t_data *minishell);
int			execute_heredoc(t_data *minishell, t_cmd *current, int i);
// heredoc_utils.c
int			warning_heredoc(t_data *ms, char *raw);
int			heredocs_processing(t_data *minishell, t_cmd *head);
char		*add_newline(char *s);
char		*setup_heredoc(t_data *ms, int **pipefd, t_cmd *current, int i);
// infile_redirections.c
int			infile_redirections(t_data *minishell, t_cmd *head);
// output_redirections.c
int			output_redirections(t_data *minishell, t_cmd *head);
// exec.c
int			execute(t_data *minishell, t_cmd *head);
int			exec_command_builtin(t_cmd **current, t_data *data);
void		exec_non_builtin(t_cmd *current, t_cmd *head, t_data *minishell);
// exec_utils.c
void		clean_and_exit(t_cmd **head, t_data *ms, int code);
void		reset_std_fd(t_data *ms);
void		check_env_size(t_data *ms, t_cmd **head, t_cmd *curr);
void		cleanup_pipes(t_data *ms);
int			handle_pipe_error(t_data *ms, const char *location);
// exec_utils2.c
void		handle_parent_signal(t_data *minishell, int *prev_fd_to_read);
int			is_valid_absolute_path(char *cmd);
int			is_absolute_path(char *cmd);
void		handle_path_error(int status, t_cmd *curr, t_data *ms, t_cmd *head);
// pipes.c
int			exec_pipes(t_cmd **head, t_data *minishell);
// pipes_redirections.c
int			handle_pipe_child_fds(int prev, t_cmd *curr, t_data *minishell);
void		close_and_reassign_fd(int *fd);
void		close_other_fds(t_cmd *current, t_cmd **head);
// redirections_fd_utils.c
int			start_redirections_fds(t_cmd *current, t_data *minishell);
int			reset_redirections_fds(t_data *minishell);

#endif
