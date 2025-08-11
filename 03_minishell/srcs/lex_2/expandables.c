/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 03:31:47 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/27 17:21:23 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	extract_env_var(char **rl_ptr, char **out_ptr, t_data *minishell)
{
	char	*var;
	char	*str_var;
	char	*out;
	char	*rl;

	rl = (*rl_ptr) + 1;
	out = *out_ptr;
	var = ft_calloc(1, sizeof(char));
	if (!var)
		return ;
	while ((ft_isalnum(*rl) || *rl == '_') && !ft_iswhitespace(*rl))
		var = ft_str_add_char(var, *(rl++));
	if (*rl == '?' && rl++)
		str_var = ft_itoa(minishell->old_exit_code);
	else
		str_var = get_env_line(var, minishell->env);
	free(var);
	if (str_var)
	{
		out = ft_strfjoin(out, str_var);
		free(str_var);
	}
	*out_ptr = out;
	*rl_ptr = rl;
}

static int	should_i_add_char(char *r, t_bool expand)
{
	if (*r && *r != '$')
		return (1);
	else if (*r == '$' && (*(r + 1) == ' '))
		return (1);
	else if (!ft_isalpha(*(r + 1)))
		return (1);
	else if (expand == 's')
		return (1);
	return (0);
}

static void	loop_env(char *r, char **o, char expand, t_data *minishell)
{
	char	*out;

	out = *o;
	while (*r)
	{
		if (*r == 39 && expand == 'n')
			expand = 's';
		else if (*r == 39 && expand == 's')
			expand = 'n';
		if (*r == 34 && expand == 'n')
			expand = 'd';
		else if (*r == 34 && expand == 'd')
			expand = 'n';
		if (*r == '$' && (ft_isalpha(*(r + 1)) || *(r + 1) == '?')
			&& (expand == 'n' || expand == 'd'))
			extract_env_var(&r, &out, minishell);
		else if (should_i_add_char(r, expand))
			out = ft_str_add_char(out, *(r++));
		else
		{
			while (*r && *r != ' ' && *r != 34 && *r != 39)
				r++;
		}
	}
	*o = out;
}

char	*expand_env_var(char *rl, t_data *minishell)
{
	char	*r;
	char	*out;

	r = rl;
	if (!*rl)
		return (free(rl), NULL);
	out = ft_calloc(ft_strlen(rl), sizeof(char));
	if (!out)
		return (free(rl), NULL);
	loop_env(r, &out, 'n', minishell);
	free(rl);
	return (out);
}
