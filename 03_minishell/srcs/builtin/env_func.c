/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:27:29 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/28 05:45:21 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lil_case(char **new_var, char *new, t_data *data)
{
	if (!ft_strncmp(*new_var, "PATH", ft_strlen(*new_var)))
	{
		free_strs(data->paths);
		data->paths = get_paths(data->env);
		if (!data->paths)
		{
			data->env_size = 0;
			if (new_var)
				free_strs(new_var);
			return (1);
		}
	}
	data->env_size += ft_strlen(new);
	free_strs(new_var);
	return (0);
}

int	export_env(t_data *data, char *new)
{
	char	**new_var;

	new_var = NULL;
	export_arg_check(data, new);
	if (!new || !*new)
		return (add_export(data, NULL), 0);
	else
		new_var = ft_split(new, '=');
	if (check_new_var(new_var))
		return (1);
	if (ft_strlen(new_var[0]) > PATH_MAX)
		return (free_strs(new_var), 1);
	if (get_index_env_line(new_var[0], data->env, 0) < 0)
	{
		data->env = ft_strsfjoin(data->env, new);
		if (new_var[1])
			return (add_export(data, new), lil_case(new_var, new, data));
		add_export(data, new_var[0]);
	}
	else
	{
		set_env_line(new_var[0], data->env, new_var[1]);
		replace_export_line(data, new, new_var[0]);
	}
	return (lil_case(new_var, new, data));
}

int	unset_env(t_data *data, char *new)
{
	int		i;
	char	**env;

	i = get_index_env_line(new, data->export, 7);
	if (i == -1)
		return (0);
	del_one_strs(data->export, i);
	i = get_index_env_line(new, data->env, 0);
	if (i == -1)
		return (0);
	env = data->env;
	del_one_strs(env, i);
	if (!ft_strncmp(new, "PATH", ft_strlen(new)))
	{
		if (data->paths)
			free_strs(data->paths);
		data->paths = NULL;
	}
	data->env_size = ft_str_strs_len(data->env);
	return (0);
}

int	print_env(t_data *minishell)
{
	int		i;
	char	**env;
	char	*line;

	if (minishell->env_size >= ARG_MAX)
	{
		ft_fprintf(2, "%s: builtin env: Argument list too long\n",
			minishell->name);
		return (126);
	}
	i = 0;
	env = minishell->env;
	while (env[i])
	{
		line = ft_strdup(env[i]);
		ft_printf("%d: %s\n", i, line);
		free(line);
		i++;
	}
	return (0);
}

void	del_one_strs(char **strs, int pos)
{
	if (pos < 0)
		return ;
	free(strs[pos]);
	while (strs[pos + 1])
	{
		strs[pos] = strs[pos + 1];
		pos++;
	}
	strs[pos] = NULL;
}
