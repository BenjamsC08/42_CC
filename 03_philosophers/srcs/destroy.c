/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:02:19 by benjamsc          #+#    #+#             */
/*   Updated: 2025/07/20 20:24:22 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_all(t_obs **ptr_obs)
{
	t_obs			*obs;
	static t_uint	i = -1;

	obs = *ptr_obs;
	if (!obs)
		return ;
	if (obs->mtx_count > 0)
		pthread_mutex_destroy(&obs->mtx_run);
	if (obs->mtx_count > 1)
		pthread_mutex_destroy(&obs->mtx_disp);
	if (obs->mtx_count > 2)
	{
		while (++i < (obs->nb_philo))
			pthread_mutex_destroy(&obs->mtx_forks[i]);
	}
	if (obs->mtx_forks)
		free(obs->mtx_forks);
	if (obs->philos)
		free(obs->philos);
	if (obs->philos_t)
		free(obs->philos_t);
	if (obs->jobs_done)
		free(obs->jobs_done);
	free(obs);
}

void	unlock_forks(pthread_mutex_t **f, pthread_mutex_t **s)
{
	pthread_mutex_unlock(*f);
	pthread_mutex_unlock(*s);
}

void	*case_only_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->data_obs->mtx_run);
	philo->data_obs->run = FALSE;
	pthread_mutex_unlock(&philo->data_obs->mtx_run);
	print_routine(philo, FORK);
	usleep(philo->data_obs->time_to_die * 1000);
	return (print_routine(philo, DEAD), NULL);
}
