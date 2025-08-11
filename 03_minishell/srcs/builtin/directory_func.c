/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:44:16 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/27 17:21:45 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	actual_directory(t_data *ms)
{
	char	*path;

	path = get_env_line("PWD", ms->env);
	if (!path)
		return (error_env(ms, NULL, -11), 1);
	ft_printf("%s\n", path);
	free(path);
	return (0);
}

void	update_var_path(char *path, t_data *ms)
{
	if (ms->pwd)
		free(ms->pwd);
	ms->pwd = ft_strdup(path);
}

static int	safe_exit(char *old_path, char *path_to)
{
	if (old_path)
		free(old_path);
	if (path_to)
		free(path_to);
	return (1);
}

int	change_directory(char **cmd, t_data *ms)
{
	char	*path_to;
	char	*old_path;
	char	*path;
	int		tmp;

	old_path = get_old_path(ms);
	if (!old_path)
		return (1);
	path_to = get_path_to(cmd, ms);
	if (!path_to)
		return (free(old_path), error_env(ms, "HOME", -5), 1);
	tmp = chdir((const char *)path_to);
	if (tmp != 0)
		return (error_env(ms, path_to, -4), safe_exit(old_path, path_to));
	path = ft_calloc(sizeof(char), PATH_MAX + 1);
	if (!path)
		return (safe_exit(old_path, path_to));
	if (!getcwd(path, PATH_MAX))
		return (error_env(ms, path_to, -4), free(path), free(path_to),
			free(old_path), 1);
	if (!set_env_line("PWD", ms->env, path))
		return (free(path), free(path_to), free(old_path), 1);
	update_var_path(path, ms);
	set_env_line("OLDPWD", ms->env, old_path);
	return (free(path), free(path_to), free(old_path), 0);
}

int	quit_ms(t_data *ms, char **strs)
{
	int	a;

	ft_fprintf(2, "exit\n");
	if (!*strs)
		a = ms->old_exit_code;
	else if (!ft_only_digit(*strs))
	{
		ft_fprintf(2, "%s : exit: %s: numeric argument required\n", ms->name,
			*strs);
		a = 2;
	}
	else
	{
		if (ft_strslen(strs) == 1)
			a = ft_atoi(*strs);
		else
			return (ft_fprintf(2, "%s : exit: too many arguments\n", ms->name),
				1);
	}
	if (ms->head && *(ms->head))
		free_list(ms->head);
	if (ms)
		destroy_data(ms);
	exit(a);
}
