/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:39:54 by benjamsc          #+#    #+#             */
/*   Updated: 2025/02/26 11:39:57 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

char	*g_str;

void	ft_up(char o)
{
	char	*temp;
	int		size_str;

	size_str = ft_strlen(g_str);
	temp = ft_strdup(g_str);
	free(g_str);
	g_str = ft_calloc(size_str + 2, sizeof(char));
	ft_memcpy(g_str, temp, (unsigned)size_str);
	g_str[size_str] = o;
	free(temp);
}

void	disp_str(int *client_pid)
{
	ft_putstr_fd(g_str, 1);
	free(g_str);
	g_str = NULL;
	kill(*client_pid, SIGUSR2);
	*client_pid = 0;
}

void	sig_handler(int signum, siginfo_t *info, void *unused)
{
	static int				pid = 0;
	static int				count = 0;
	static unsigned char	octet = 1;

	(void)unused;
	if (pid == 0)
		pid = info->si_pid;
	if (!g_str)
		g_str = (char *)ft_calloc(1, sizeof(char));
	octet <<= 1;
	count++;
	if (signum == SIGUSR1)
		octet |= 1;
	if (count == 8)
	{
		count = 0;
		if (octet == 0)
		{
			octet = 1;
			return (disp_str(&pid));
		}
		ft_up(octet);
		octet = 1;
	}
	kill(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID server :%d\n", getpid());
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
	{
		pause();
	}
	return (0);
}
