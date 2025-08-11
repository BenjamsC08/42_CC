/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:24:54 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/28 05:46:17 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_old_path(t_data *ms)
{
	char	*old_path;

	old_path = get_env_line("PWD", ms->env);
	if (!old_path)
		old_path = ft_strdup(ms->pwd);
	if (!old_path)
		return (NULL);
	return (old_path);
}

char	*get_path_to(char **cmd, t_data *ms)
{
	char	*path_to;

	path_to = ft_strdup(cmd[1]);
	if (!path_to)
		path_to = get_env_line("HOME", ms->env);
	if (!path_to)
		return (NULL);
	return (path_to);
}

void	print_export(char **export)
{
	char	**splt;
	int		i;

	while (*export)
	{
		splt = ft_split(*export, '=');
		if (!splt)
			return ;
		ft_fprintf(1, "%s", splt[0]);
		if (splt[1])
		{
			i = 1;
			ft_printf("=\"");
			while (splt[i])
				ft_fprintf(1, "%s", splt[i++]);
			ft_printf("\"");
		}
		ft_printf("\n");
		export ++;
		free_strs(splt);
	}
}

int	check_new_var(char **new_var)
{
	if (!new_var)
		return (1);
	if (!new_var[0])
		return (free(new_var), 1);
	return (0);
}
