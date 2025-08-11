/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 03:24:26 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/27 00:56:18 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_var_check(char *str)
{
	char	*charset;
	int		k;

	charset = "(){}[]\\/&!";
	while (*str)
	{
		k = ft_is_in(*str, charset);
		if (k != 0)
			return (0);
		str++;
	}
	return (1);
}

static char	*loop_arg(char *src, char *str, char *s, t_data *ms)
{
	while (*src && *src != '=')
	{
		if (!ft_isalnum(*src) && *src != '_')
			return (free(s), error_env(ms, str, -20), NULL);
		src++;
	}
	return (src);
}

int	export_arg_check(t_data *minishell, char *str)
{
	char	*src;
	char	*s;

	if (!str)
		return (0);
	src = ft_strdup(str);
	if (!src)
		return (0);
	s = src;
	if (*src == '"')
		src++;
	if (*src == '-')
		return (free(s), error_env(minishell, str, -21), 2);
	if (!ft_isalpha(*src) && *src != '_')
		return (free(s), error_env(minishell, str, -20), 1);
	src = loop_arg((++src), str, s, minishell);
	if (!src)
		return (1);
	if (!*src)
		return (free(s), 0);
	else if (export_var_check(++src))
		return (free(s), 0);
	else
		return (free(s), 1);
}
