/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:44:22 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/28 05:45:45 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin_cmd(char *cmd)
{
	if (!ft_strncmp(cmd, "cd", 2))
		return (1);
	if (!ft_strncmp(cmd, "pwd", 3))
		return (1);
	if (!ft_strncmp(cmd, "export", 6))
		return (1);
	if (!ft_strncmp(cmd, "unset", 5))
		return (1);
	if (!ft_strncmp(cmd, "env", 3))
		return (1);
	if (!ft_strncmp(cmd, "echo\0", 5) || !ft_strncmp(cmd, "echo ", 5))
		return (1);
	if (!ft_strncmp(cmd, "exit", 4))
		return (1);
	return (0);
}

int	get_index_env_line(char *type, char **env, t_uint offset)
{
	int	i;
	int	l;
	int	k;

	i = 0;
	if (!type || !env)
		return (-1);
	k = ft_strlen(type);
	while (env[i])
	{
		l = ft_strlen_to((env[i] + offset), '=');
		if (k > l)
			l = k;
		if (!ft_strncmp((env[i] + offset), type, l))
			break ;
		i++;
	}
	if (!env[i])
		i = -1;
	return (i);
}

char	*get_env_line(char *type, char **env)
{
	char	*s;
	int		i;

	i = get_index_env_line(type, env, 0);
	if (i == -1 || !*(env[i] + ft_strlen(type) + 1))
		return (NULL);
	s = ft_strdup(env[i] + (ft_strlen(type) + 1));
	if (!s)
		return (NULL);
	return (s);
}

int	set_env_line(char *type, char **env, char *to)
{
	char	*t;
	int		i;

	i = get_index_env_line(type, env, 0);
	t = ft_strjoin(type, "=");
	if (!t || !*t)
		return (0);
	if (to)
		t = ft_strfjoin(t, to);
	if (i >= 0 && env[i])
		free(env[i]);
	else
	{
		i = 0;
		while (env[i])
			i++;
	}
	env[i] = ft_strdup(t);
	free(t);
	return (1);
}

int	swap_str(char **s1, char **s2)
{
	char	*s;
	char	*d;

	s = ft_strdup(*s1);
	if (!s)
		return (0);
	d = ft_strdup(*s2);
	if (!d)
		return (free(s), 0);
	free(*s1);
	free(*s2);
	*s1 = d;
	*s2 = s;
	return (1);
}
