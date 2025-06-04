/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:40:07 by benjamsc          #+#    #+#             */
/*   Updated: 2025/02/26 11:40:10 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int		g_ok = 0;

void	send_bits(int pid, char c)
{
	int				i;
	unsigned char	tmp;
	unsigned char	octet;

	octet = ft_reverse_bits(c);
	i = 0;
	while (i < 8)
	{
		g_ok = 0;
		tmp = (octet & 1);
		if (tmp == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		octet >>= 1;
		i++;
		while (g_ok != 1)
			pause();
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
	{
		exit(0);
	}
	else
		g_ok = 1;
}

void	send_char(int pid, char *str)
{
	while (*str)
	{
		send_bits(pid, *str);
		str++;
	}
	send_bits(pid, 0);
}

void	c(int pid, char *str)
{
	while (42)
	{
		send_char(pid, str);
	}
}

int	main(int arc, char **arv)
{
	struct sigaction	sa;
	int					pid;

	if (arc != 3 || !only_digits(arv[1]))
		return (err_handler(-1), 1);
	pid = ft_atoi(arv[1]);
	if (!arv[2][0] || kill(pid, 0))
		return (err_handler(-2), 1);
	sa.sa_handler = &sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	c(pid, arv[2]);
}
