/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:58:57 by mkerrien          #+#    #+#             */
/*   Updated: 2025/05/30 11:02:02 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	need_reset_to_one(char *s)
{
	int	i;

	i = -1;
	while (++i < 3 && s[i])
	{
		if (ft_isdigit(s[i]))
			continue ;
		else
			return (-1);
	}
	if (s[i])
		return (-1);
	else if (!s[i] && (ft_isdigit(s[i - 1]) && s[i - 1] < '9'))
		return (0);
	else
		return (-1);
}

void	update_shell_lvl(t_data *minishell)
{
	int		i;
	char	*old;
	char	*lvl_str;

	old = NULL;
	i = get_index_env_line("SHLVL", minishell->env, 0);
	if (i > -1)
		old = ft_strchr(minishell->env[i], '=');
	if (!old || need_reset_to_one(++old))
		set_env_line("SHLVL", minishell->env, "1");
	else
	{
		lvl_str = ft_itoa(ft_atoi(old) + 1);
		if (lvl_str)
		{
			set_env_line("SHLVL", minishell->env, lvl_str);
			free(lvl_str);
			lvl_str = NULL;
		}
	}
}

char	*remove_first_char(char *s)
{
	char	*dst;

	dst = NULL;
	if (!s)
		return (ft_strdup("minishell"));
	if (s[0] && s[1] && (s[0] == '.' && s[1] == '/'))
		dst = ft_strldup(s + 2, ft_strlen(s) - 2);
	if (!dst)
		return (free(s), s = NULL, ft_strdup("minishell"));
	free(s);
	return (dst);
}
