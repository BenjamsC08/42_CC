/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:06:14 by benjamsc          #+#    #+#             */
/*   Updated: 2025/07/12 17:08:18 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_eaten(t_obs *obs)
{
	t_uint	i;

	i = -1;
	while (++i < obs->nb_philo)
	{
		if (obs->jobs_done[i] != 1)
			return (0);
	}
	obs->run = FALSE;
	return (1);
}

void	*obs_routines(void *ptr_obs)
{
	t_obs	*obs;
	t_uint	i;
	t_uint	t;

	obs = (t_obs *)ptr_obs;
	i = 0;
	while (42)
	{
		pthread_mutex_lock(&obs->mtx_run);
		if (obs->run == FALSE || all_eaten(obs))
			return (obs->run = 0, pthread_mutex_unlock(&obs->mtx_run), NULL);
		t = get_current_time() - obs->philos[i].last_meal;
		pthread_mutex_unlock(&obs->mtx_run);
		if (t > obs->time_to_die && obs->philos[i].last_meal != -1)
		{
			pthread_mutex_lock(&obs->mtx_run);
			obs->run = FALSE;
			pthread_mutex_unlock(&obs->mtx_run);
			print_routine(&obs->philos[i], DEAD);
			return (NULL);
		}
		i++;
		if (i == obs->nb_philo)
			i = 0;
	}
}

/*void	*obs_routines(void *ptr_obs)*/
/*{*/
/*	t_obs			*obs;*/
/*	static t_uint	i = -1;*/
/*	t_uint			t;*/
/**/
/*	obs = (t_obs *)ptr_obs;*/
/*	while (++i)*/
/*	{*/
/*		pthread_mutex_lock(&obs->mtx_run);*/
/*		if (all_eaten(obs))*/
/*			obs->run = FALSE;*/
/*		if (obs->run == FALSE)*/
/*			return (pthread_mutex_unlock(&obs->mtx_run), NULL);*/
/*		t = get_current_time() - obs->philos[i].last_meal;*/
/*		pthread_mutex_unlock(&obs->mtx_run);*/
/*		if (t > obs->time_to_die && obs->philos[i].last_meal != -1)*/
/*		{*/
/*			pthread_mutex_lock(&obs->mtx_run);*/
/*			obs->run = FALSE;*/
/*			pthread_mutex_unlock(&obs->mtx_run);*/
/*			return (print_routine(&obs->philos[i], DEAD), NULL);*/
/*		}*/
/*		if (i == obs->nb_philo)*/
/*			i = 0;*/
/*	}*/
/*	return (NULL);*/
/*}*/
