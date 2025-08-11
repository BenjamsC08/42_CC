/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:39:16 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/27 09:44:37 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**all_path(char **paths);
char	**init_path(char **envp);

char	**get_paths(char **envp)
{
	char	**env;
	int		i;

	env = init_path(envp);
	if (!env || !*env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		env[i] = ft_strfjoin(env[i], "/");
		if (!env[i])
			return (free_strs(env), NULL);
		i++;
	}
	return (env);
}

char	**init_path(char **envp)
{
	char	*path;
	char	**paths;

	path = NULL;
	paths = NULL;
	if (!envp || !*envp)
		return (NULL);
	while (*envp)
	{
		path = ft_strnstr((const char *)*envp, "PATH=", 5);
		if (path)
		{
			path = ft_substr((const char *)*envp, 5, ft_strlen(path));
			if (!path)
				return (NULL);
			break ;
		}
		envp++;
	}
	paths = ft_split(path, ':');
	if (path)
		free(path);
	return (all_path(paths));
}

char	*extract_path(char *path)
{
	unsigned int	i;
	unsigned int	l;
	char			*str;

	str = NULL;
	i = -1;
	l = 0;
	while (path[++i])
	{
		if (path[i] == '/')
			l = i;
	}
	str = ft_substr((const char *)path, 0, l);
	if (!str)
		return (NULL);
	return (str);
}

int	is_in(char **strs, char *str)
{
	int	i;

	i = 0;
	if (str[0] == 0)
		return (1);
	while (strs[i])
	{
		if (!ft_strncmp((const char *)strs[i], (const char *)str,
				(ft_strlen(strs[i]) + ft_strlen(str))))
			return (1);
		i++;
	}
	return (0);
}

char	**all_path(char **paths)
{
	int		i;
	char	*str;

	i = -1;
	while (paths[++i])
	{
		str = extract_path(paths[i]);
		if (!str)
			return (free_strs(paths), NULL);
		if (!is_in(paths, str))
			paths = ft_strsfjoin(paths, str);
		free(str);
	}
	return (paths);
}
