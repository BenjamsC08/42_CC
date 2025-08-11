/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:56:49 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/27 00:56:49 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_whitespace(char **str)
{
	int	l;

	l = 0;
	while (**str && ft_iswhitespace(**str))
	{
		(*str)++;
		l++;
	}
	return (l);
}

char	*skip_whitespace_del_tab(char **str)
{
	char	*src;
	char	*dest;
	char	*d;

	src = *str;
	skip_whitespace(&src);
	dest = ft_calloc(sizeof(char), ft_strlen(*str) + 1);
	if (!dest)
		return (*str);
	d = dest;
	while (*src)
	{
		if (*src == 11 || *src == 9)
			*(d++) = 32;
		else
			*(d++) = *src;
		src++;
	}
	*d = 0;
	free(*(str));
	return (dest);
}

char	*get_str_status(char **str, t_data *data)
{
	char	*rl;
	char	*str_var;

	rl = *str;
	if (g_sig != 0)
		str_var = ft_itoa(g_sig);
	else
		str_var = ft_itoa(data->status);
	rl++;
	*str = rl;
	return (str_var);
}

void	print_lex(t_dlist **head)
{
	t_dlist	*curr;
	int		i;

	curr = *head;
	i = 0;
	while (curr)
	{
		ft_fprintf(2, "i:%d->token:'%s'->type:'%c'\n", i, get_token(curr),
			get_type(curr));
		i++;
		curr = curr->next;
	}
}
