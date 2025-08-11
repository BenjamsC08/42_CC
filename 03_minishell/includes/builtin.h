/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:21:02 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/28 06:19:29 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

// path_management.c
char	**get_paths(char **envp);
// builtin utils.c
int		get_index_env_line(char *type, char **env, t_uint offset);
int		is_builtin_cmd(char *cmd);
char	*get_env_line(char *type, char **env);
int		set_env_line(char *type, char **envp, char *to);
int		swap_str(char **s1, char **s2);
// directory_func.c
int		change_directory(char **cmd, t_data *data);
int		actual_directory(t_data *data);
int		quit_ms(t_data *data, char **strs);
// env_func.c
int		export_env(t_data *data, char *new);
int		unset_env(t_data *data, char *new);
int		print_env(t_data *data);
// export_env.c
void	add_export(t_data *data, char *str);
char	**init_export(char **envp);
void	replace_export_line(t_data *data, char *new, char *to_find);
// echo_func.c
int		echo_func(char **cmd);
// getter_utils.c
char	*get_old_path(t_data *ms);
char	*get_path_to(char **cmd, t_data *ms);
int		check_new_var(char **new_var);
//
void	del_one_strs(char **strs, int pos);
void	print_export(char **export);

#endif
