/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:36:20 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/27 01:21:25 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			g_sig = 0;

static void	destroy_data_2(t_data *data)
{
	if (data->pids)
	{
		free(data->pids);
		data->pids = NULL;
	}
	if (data->pipes)
	{
		if (data->pipes[0] != -1)
			close(data->pipes[0]);
		data->pipes[0] = -1;
		if (data->pipes[1] != -1)
			close(data->pipes[1]);
		data->pipes[1] = -1;
		free(data->pipes);
		data->pipes = NULL;
	}
	if (data->stdin != -1)
		close(data->stdin);
	data->stdin = -1;
	if (data->stdout != -1)
		close(data->stdout);
	data->stdout = -1;
}

void	destroy_data(t_data *data)
{
	if (data->name)
	{
		free(data->name);
		data->name = NULL;
	}
	if (data->cmd)
		ft_free_fullstrs(&data->cmd);
	if (data->paths && *(data->paths))
		ft_free_fullstrs(&data->paths);
	if (data->env)
		ft_free_fullstrs(&data->env);
	if (data->pwd)
	{
		free(data->pwd);
		data->pwd = NULL;
	}
	if (data->export)
		ft_free_fullstrs(&data->export);
	if (data->delimiter)
	{
		free(data->delimiter);
		data->delimiter = NULL;
	}
	destroy_data_2(data);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		code;
	int		res;

	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(data));
	init_sig();
	if (!envp || !*envp)
	{
		res = init_data_safe(&data, argv);
		if (res)
			return (destroy_data(&data), res);
	}
	else
	{
		res = init_data(&data, argv, envp);
		if (res)
			return (destroy_data(&data), res);
	}
	code = ft_term(&data);
	destroy_data(&data);
	return (code);
}
