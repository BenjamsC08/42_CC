/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 02:39:10 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 01:15:21 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_error(char *s, t_data *minishell)
{
	ft_fprintf(2, "%s: %s: Too many open files\n", minishell->name, s);
}

void	error_env(t_data *ms, char *str, int code)
{
	(void)code;
	if (code == -20)
		ft_fprintf(2, "%s: %s : not a valid identifier\n", ms->name, str);
	else if (code == -21)
		ft_fprintf(2, "%s: %s : invalid option\n", ms->name, str);
	else if (code == -4)
		ft_fprintf(2, "%s: cd: %s: No such file or directory\n", ms->name, str);
	else if (code == -5)
		ft_fprintf(2, "%s: cd: %s not set\n", ms->name, str);
	else if (code == -11)
	{
		ft_fprintf(2, "pwd: error retrieving current directory: getcwd: ");
		ft_fprintf(2, "cannot access parent directories:");
		ft_fprintf(2, "No such file or directory\n");
	}
}
