/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 05:19:38 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/02 05:01:21 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_child(int signum)
{
	if (signum == SIGINT)
		g_sig = 130;
}

void	sig_parent(int signum)
{
	if (signum == SIGINT)
	{
		if (g_sig == 42)
		{
			close(0);
			ft_fprintf(1, "\n");
		}
		else
			reset_term(130);
		g_sig = 130;
	}
}

void	init_sig(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_parent);
}

void	check_status(int *status, t_data *minishell)
{
	if (WIFSIGNALED(*status))
	{
		if (WTERMSIG(*status) == SIGINT)
		{
			*status += 128;
			g_sig = 130;
		}
		else if (WTERMSIG(*status) == SIGKILL)
		{
			ft_fprintf(2, "Killed\n");
			*status += 128;
		}
		else if (WTERMSIG(*status) == SIGQUIT)
		{
			ft_fprintf(2, "Quit (core dumped)\n");
		}
		minishell->exit_code = *status;
	}
	else
		*status >>= 8;
}

// ca pue la merde mais ca fait gagner des ligne all my homies hate NORMINETTE
/*int	sig_man(t_data *data)*/
/*{*/
/*	if (g_sig == 130)*/
/*	{*/
/*		data->exit_code = g_sig;*/
/*		g_sig = 1;*/
/*		return (1);*/
/*	}*/
/*	else if (g_sig == 1)*/
/*	{*/
/*		data->exit_code = 0;*/
/*		g_sig = 0;*/
/*		return (0);*/
/*	}*/
/*	return (0);*/
/*}*/
