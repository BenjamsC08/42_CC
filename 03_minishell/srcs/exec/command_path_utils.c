/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:09:45 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 15:12:35 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	test_all_paths(char **paths, char **path, char **cmd, int *found)
{
	int	i;

	i = 0;
	*path = ft_strjoin(paths[i], "/");
	*path = ft_strfjoin(*path, *cmd);
	while (paths[i])
	{
		if (*path)
			free(*path);
		*path = ft_strjoin(paths[i], "/");
		*path = ft_strfjoin(*path, *cmd);
		if (access(*path, F_OK) == 0)
			*found = 1;
		if (access(*path, F_OK | X_OK) == 0)
			break ;
		i++;
	}
}

static char	*find_right_path(char **paths, char *cmd, t_data *minishell)
{
	int		found;
	char	*path;

	found = 0;
	test_all_paths(paths, &path, &cmd, &found);
	if (!found || (found && access(path, X_OK)))
	{
		if (!found)
		{
			if (minishell->exit_code == 0)
				command_not_found(minishell, cmd);
			minishell->exit_code = 127;
		}
		else if (found && access(path, X_OK))
		{
			if (minishell->exit_code == 0)
				permission_error(minishell, cmd);
			minishell->exit_code = 126;
		}
		return (free(path), path = NULL);
	}
	return (path);
}

static int	get_all_paths(char ***paths, char **envp)
{
	int		i;
	char	*tmp;
	char	*path;

	i = -1;
	tmp = NULL;
	if (!envp)
		return (1);
	while (envp[++i] && ft_strncmp(envp[i], "PATH=", 5))
		;
	if (!envp[i])
		return (1);
	tmp = ft_strdup(envp[i]);
	if (!tmp || !envp[i])
		return (1);
	path = ft_substr(tmp, 5, ft_strlen(tmp) - 5);
	if (!path)
		return (free(tmp), 1);
	free(tmp);
	*paths = ft_split(path, ':');
	if (!*paths)
		return (free(path), 1);
	free(path);
	return (0);
}

int	find_cmd_path(char **cmd, t_data *minishell, char **envp)
{
	char	*path;
	char	**paths;

	if (get_all_paths(&paths, envp))
		return (1);
	path = find_right_path(paths, cmd[0], minishell);
	if (paths)
		ft_free_fullstrs(&paths);
	if (!path)
		return (1);
	return (free(cmd[0]), cmd[0] = path, 0);
}
