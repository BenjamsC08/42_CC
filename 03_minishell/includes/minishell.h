/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:35:20 by benjamsc          #+#    #+#             */
/*   Updated: 2025/05/04 03:14:41 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// hand make
# include "libft.h"
# include "common.h"
# include "parsing.h"
# include "myexec.h"
# include "builtin.h"
# include "lex.h"
// standard
# include <errno.h>
# include <curses.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

extern int	g_sig;

int			ft_term(t_data *data);
// signal_management.c
int			sig_man(t_data *data);
void		init_sig(void);
void		sig_child(int signum);
void		sig_heredoc(int signum);
void		sig_parent(int signum);
void		check_status(int *status, t_data *minishell);
// error_management.c
void		command_not_found(t_data *ms, char *cmd);
void		syntax_error(t_data *ms, char *s);
void		inexistant_file_error(t_data *ms, char *s);
void		permission_error(t_data *ms, char *s);
void		outfile_error(t_data *ms, char *s);
void		free_all_data(t_data *data);
void		error_env(t_data *ms, char *str, int code);
void		fd_error(char *s, t_data *minishell);
// init_data.c
int			init_data(t_data *data, char **argv, char **envp);
int			init_data_safe(t_data *data, char **argv);
// init_data_utils.c
void		update_shell_lvl(t_data *minishell);
char		*remove_first_char(char *s);
// utils.c
int			alloc_check(void *ptr, t_data *ms);
char		*ft_rl(char *color, t_data *data);
char		*colorized(void);
int			reset_term(int code);
// history.c
int			load_history(t_data *ms);
int			add_ms_history(t_data *ms, char *cmd);
// main.c
void		destroy_data(t_data *data);
// debug.c
void		print_list(t_cmd *head);
void		print_fds(t_cmd *current, t_data *minishell);

#endif
