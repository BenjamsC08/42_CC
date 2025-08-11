/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:46:34 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/28 06:19:11 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	alloc_check(void *ptr, t_data *ms)
{
	if (!ptr)
	{
		ms->exit_code = 1;
		return (0);
	}
	return (1);
}

/*char    *build_prompt(char *color, t_data *ms)*/
/*{*/
/*    char    *prompt;*/
/*    char    *ec;*/
/**/
/*    if (g_sig == 130)*/
/*	{*/
/*        ec = ft_itoa(130);*/
/*		color = RED;*/
/*	}*/
/*    else*/
/*        ec = ft_itoa(ms->exit_code);*/
/*    prompt = ft_strdup(color);*/
/*    prompt = ft_str_add_char(prompt, '[');*/
/*    prompt = ft_strfjoin(prompt, ec);*/
/*    free(ec);*/
/*    prompt = ft_strfjoin(prompt, "] ");*/
/*    prompt = ft_strfjoin(prompt, ms->name);*/
/*    prompt = ft_strfjoin(prompt, "$>\033[0;0m \0");*/
/*    return (prompt);*/
/*}*/

char	*ft_rl(char *color, t_data *data)
{
	char	*rl;

	rl = NULL;
	ft_printf("%s[%d] %s", color, data->exit_code, data->name);
	rl = readline("$>\033[0;0m \0");
	return (rl);
}

char	*colorized(void)
{
	static int	i = 0;

	i++;
	if (i == 0)
		return (GREEN);
	else if (i == 1)
		return (CYAN);
	else if (i == 2)
		return (MAGENTA);
	else if (i == 3)
		return (BLUE);
	else if (i == 4)
		return (YELLOW);
	else if (i == 6)
		return (TEAL);
	else if (i == 7)
		return (PINK);
	else if (i == 8)
		return (GRAY);
	else
		i = -1;
	return (RESET);
}

int	reset_term(int code)
{
	(void)code;
	ft_printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	ft_printf("%s[%d] ", RED, code);
	rl_redisplay();
	return (1);
}
