/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:14:15 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/26 22:25:29 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	check_nl(char **ptr_str)
{
	char			*str;
	static t_bool	nl = FALSE;

	str = (*ptr_str) + 1;
	if (*str != 'n')
		return (nl);
	while (*str == 'n')
		str++;
	if (*str == ' ' || !*str)
	{
		*ptr_str = str;
		nl = TRUE;
		return (nl);
	}
	return (nl);
}

t_bool	is_nl_option(char **ptr_str)
{
	t_bool	nl;
	char	*str;
	char	*save;

	nl = FALSE;
	str = *ptr_str;
	save = *ptr_str;
	while (42)
	{
		if (*str == '-')
		{
			nl = check_nl(&str);
			if (!nl)
				break ;
		}
		else
			break ;
		if (*str && *str != ' ')
			break ;
		else if (*str)
			str++;
		save = str;
	}
	*ptr_str = save;
	return (nl);
}

void	write_eco(char *s, t_bool nl)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (*s)
		i += write(1, s++, 1);
	if (nl == FALSE)
		ft_printf("\n");
}

int	echo_func(char **cmd)
{
	char	*rl;
	char	*s;
	t_bool	nl;

	nl = FALSE;
	rl = NULL;
	if (cmd && *cmd)
		rl = ft_unsplit_with_sep(cmd, ' ');
	if (!rl)
		return (1);
	s = rl;
	rl += 5;
	if (ft_strlen(s) <= 5 || !*rl)
		return (free(s), write(1, "\n", 1) - 1);
	if (is_nl_option(&rl))
		nl = TRUE;
	return (write_eco(rl, nl), free(s), 0);
}
