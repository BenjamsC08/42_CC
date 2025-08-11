/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:02:25 by benjamsc          #+#    #+#             */
/*   Updated: 2025/07/12 17:02:26 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_next_fork_id(t_obs *obs, int i)
{
	if (i == (int)(obs->nb_philo - 1))
		return (0);
	else
		return (i + 1);
}

t_uint	get_current_time(void)
{
	struct timeval	current_time;
	t_uint			out;

	gettimeofday(&current_time, NULL);
	out = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (out);
}
