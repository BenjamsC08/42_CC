/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:40:52 by benjamsc          #+#    #+#             */
/*   Updated: 2025/02/26 11:40:54 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include "libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		only_digits(char *str);
void	err_handler(int err);

#endif
