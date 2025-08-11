/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:03:46 by benjamsc          #+#    #+#             */
/*   Updated: 2025/07/12 17:12:24 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	good_one(philo, &first, &second);
	pthread_mutex_lock(first);
	if (!is_running(philo))
		return (pthread_mutex_unlock(first), 0);
	if (!print_routine(philo, FORK))
		return (pthread_mutex_unlock(first), 0);
	pthread_mutex_lock(second);
	if (!is_running(philo))
		return (unlock_forks(&first, &second), 0);
	if (!print_routine(philo, FORK))
		return (unlock_forks(&first, &second), 0);
	return (1);
}

int	eat_routine(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	good_one(philo, &first, &second);
	if (!is_running(philo))
	{
		pthread_mutex_unlock(second);
		pthread_mutex_unlock(first);
		return (0);
	}
	pthread_mutex_lock(&philo->data_obs->mtx_run);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->data_obs->mtx_run);
	philo->loop_count++;
	print_routine(philo, EAT);
	wait_for(philo, EAT);
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
	pthread_mutex_lock(&philo->data_obs->mtx_run);
	if (philo->loop_count == philo->data_obs->nb_loop)
		return (philo->data_obs->jobs_done[philo->id] = 1,
			pthread_mutex_unlock(&philo->data_obs->mtx_run), 0);
	pthread_mutex_unlock(&philo->data_obs->mtx_run);
	return (1);
}

int	think_routine(t_philo *philo)
{
	if (!is_running(philo))
		return (0);
	print_routine(philo, THINK);
	wait_for(philo, THINK);
	return (1);
}

int	sleep_routine(t_philo *philo)
{
	if (is_running(philo))
	{
		print_routine(philo, SLEEP);
		wait_for(philo, SLEEP);
		return (1);
	}
	return (0);
}

void	*philo_routines(void *ptr_philo)
{
	t_philo	*philo;

	philo = (t_philo *)ptr_philo;
	if (!is_running(philo))
		return (NULL);
	if (philo->data_obs->nb_philo == 1)
		return (case_only_one(philo));
	if (philo->id % 2 == 0)
		usleep((philo->data_obs->time_to_eat / 2) * 1000);
	while (is_running(philo) && loop_needed(philo))
	{
		if (!take_forks(philo))
			return (NULL);
		if (!eat_routine(philo))
			return (NULL);
		if (!sleep_routine(philo))
			return (NULL);
		if (!think_routine(philo))
			return (NULL);
	}
	return (NULL);
}
