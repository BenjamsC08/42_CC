/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 03:37:44 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 01:18:19 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_basics_two(t_data *minishell)
{
	minishell->stdin = dup(STDIN_FILENO);
	if (minishell->stdin == -1)
		return (fd_error("can't duplicate STDIN", minishell), 1);
	minishell->stdout = dup(STDOUT_FILENO);
	if (minishell->stdout == -1)
		return (fd_error("can't duplicate STDOUT", minishell), 1);
	minishell->pwd = ft_calloc(sizeof(char), PATH_MAX + 1);
	if (!minishell->pwd)
		return (1);
	minishell->pwd = getcwd(minishell->pwd, PATH_MAX);
	if (load_history(minishell))
		return (1);
	return (0);
}

static int	init_basics(t_data *minishell, char **argv)
{
	int	res;

	minishell->name = remove_first_char(ft_strdup(argv[0]));
	if (!minishell->name)
		minishell->name = ft_strdup("minishell");
	if (!minishell->name)
		return (1);
	minishell->exit_code = 0;
	minishell->delimiter = NULL;
	minishell->cmd = NULL;
	minishell->head = NULL;
	minishell->pids = NULL;
	minishell->pipes = ft_calloc(sizeof(int), 2);
	if (!minishell->pipes)
		return (minishell->exit_code = 1);
	minishell->pipes[0] = -1;
	minishell->pipes[1] = -1;
	res = init_basics_two(minishell);
	if (res)
		return (res);
	return (0);
}

int	init_data_safe(t_data *data, char **argv)
{
	char	**env;
	char	*str;
	int		res;

	res = init_basics(data, argv);
	if (res)
		return (res);
	env = ft_calloc(sizeof(char *), 5);
	if (!env)
		return (1);
	data->paths = ft_calloc(2, sizeof(char *));
	if (!data->paths)
		return (1);
	data->paths[0] = ft_strdup(PTH);
	if (!data->paths[0])
		return (1);
	set_env_line("PWD", env, data->pwd);
	str = ft_strjoin(data->pwd, *argv);
	set_env_line("_", env, str);
	free(str);
	data->env = env;
	update_shell_lvl(data);
	data->export = init_export(data->env);
	add_export(data, "OLD_PWD");
	return (0);
}

int	init_data(t_data *minishell, char **argv, char **envp)
{
	int	res;

	res = init_basics(minishell, argv);
	if (res)
		return (res);
	minishell->paths = ft_calloc(2, sizeof(char *));
	if (!minishell->paths)
		return (1);
	minishell->paths[0] = ft_strdup(PTH);
	if (!minishell->paths[0])
		return (1);
	minishell->env = ft_strsdup(envp);
	if (!minishell->env)
		return (1);
	update_shell_lvl(minishell);
	minishell->export = init_export(minishell->env);
	minishell->env_size = ft_str_strs_len(minishell->env);
	return (0);
}
