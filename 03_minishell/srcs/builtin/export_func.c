/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:43:34 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/28 05:46:40 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**export_normalize(char **exp)
{
	char	**out;
	char	*tmp;
	int		i;

	i = 0;
	out = exp;
	tmp = NULL;
	while (out[i])
	{
		if (ft_strncmp(out[i], "export ", 7))
		{
			tmp = ft_strdup(out[i]);
			if (!tmp)
				return (free_strs(exp), NULL);
			free(out[i]);
			out[i] = ft_strjoin("export ", tmp);
			free(tmp);
		}
		i++;
	}
	return (out);
}

char	**sort_export(char **exp)
{
	int		i;
	int		j;
	char	**s;

	s = exp;
	j = 0;
	while (s[j])
	{
		i = 0;
		while (s[i + 1])
		{
			if (ft_strncmp(s[i], s[i + 1],
					(ft_strlen(s[i]) + ft_strlen(s[i + 1]))) > 0)
			{
				if (!swap_str(&s[i], &s[i + 1]))
					return (free_strs(exp), NULL);
			}
			i++;
		}
		j++;
	}
	return (s);
}

void	add_export(t_data *data, char *str)
{
	char	**exp;
	char	*src;

	if (!str)
		return (print_export(data->export));
	if (get_index_env_line(str, data->export, 7) != -1)
		return ;
	src = ft_strjoin("export ", str);
	exp = data->export;
	exp = ft_strsfjoin(exp, src);
	free(src);
	sort_export(exp);
	data->export = exp;
}

char	**init_export(char **envp)
{
	char	**exp;

	exp = ft_strsdup(envp);
	if (!exp)
		return (NULL);
	exp = export_normalize(exp);
	if (!exp)
		return (NULL);
	exp = sort_export(exp);
	if (!exp)
		return (NULL);
	return (exp);
}

void	replace_export_line(t_data *data, char *new, char *to_find)
{
	char	**exp;
	char	**ptr_exp;
	char	*src;

	if (new)
		src = ft_strjoin("export ", new);
	else
		return ;
	exp = data->export;
	ptr_exp = exp;
	while (*exp)
	{
		if (!ft_strncmp((const char *)*exp + 7, (const char *)to_find,
				ft_strlen(to_find)))
			break ;
		exp++;
	}
	if (!*exp)
		return (free(src));
	free(*exp);
	if (new)
		*exp = src;
	sort_export(ptr_exp);
	data->export = ptr_exp;
}
