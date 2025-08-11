/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:02:29 by benjamsc          #+#    #+#             */
/*   Updated: 2025/07/12 17:02:30 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_obs **ptr_obs)
{
	t_obs	*obs;
	t_uint	i;

	obs = *ptr_obs;
	obs->mtx_count = 0;
	if (pthread_mutex_init(&obs->mtx_run, NULL) != 0)
		return (destroy_all(&obs), 0);
	obs->mtx_count++;
	if (pthread_mutex_init(&obs->mtx_disp, NULL) != 0)
		return (destroy_all(&obs), 0);
	obs->mtx_count++;
	obs->mtx_forks = ft_calloc(sizeof(t_mtx), obs->nb_philo);
	if (!obs->mtx_forks)
		return (destroy_all(&obs), 0);
	obs->mtx_count++;
	i = -1;
	while (++i < obs->nb_philo)
	{
		if (pthread_mutex_init(&obs->mtx_forks[i], NULL) != 0)
			return (destroy_all(&obs), 0);
	}
	*ptr_obs = obs;
	return (1);
}

int	init_philo_struct(t_obs **ptr_obs)
{
	t_obs	*obs;
	t_uint	i;

	obs = *ptr_obs;
	i = -1;
	obs->philos = ft_calloc(sizeof(t_philo), obs->nb_philo);
	if (!obs->philos)
		return (destroy_all(&obs), 0);
	while (++i < obs->nb_philo)
	{
		obs->philos[i].id = i;
		obs->philos[i].last_meal = 0;
		obs->philos[i].loop_count = 0;
		obs->philos[i].r_fork = &obs->mtx_forks[i];
		obs->philos[i].l_fork = &obs->mtx_forks[get_next_fork_id(obs, i)];
		obs->philos[i].data_obs = *ptr_obs;
	}
	return (1);
}

t_obs	*build_obs(int *tab_values)
{
	t_obs	*obs;

	obs = ft_calloc(sizeof(t_obs), 1);
	if (!obs)
		return (NULL);
	obs->nb_philo = tab_values[0];
	obs->time_to_die = tab_values[1];
	obs->time_to_eat = tab_values[2];
	obs->time_to_sleep = tab_values[3];
	obs->nb_loop = -1;
	if (tab_values[4])
		obs->nb_loop = tab_values[4];
	obs->jobs_done = ft_calloc(tab_values[0], sizeof(int));
	if (!obs->jobs_done)
		return (NULL);
	obs->run = FALSE;
	if (!init_mutexes(&obs))
		return (NULL);
	if (!init_philo_struct(&obs))
		return (NULL);
	return (obs);
}

int	start_threads(t_obs *obs)
{
	t_uint	i;

	obs->philos_t = ft_calloc(sizeof(pthread_t), obs->nb_philo);
	if (!obs->philos_t)
		return (destroy_all(&obs), 0);
	pthread_mutex_lock(&obs->mtx_run);
	if (pthread_create(&obs->obs_thread, NULL, (void *)obs_routines,
			(void *)obs) != 0)
		return (free(obs->philos_t), destroy_all(&obs), 0);
	i = -1;
	while (++i < obs->nb_philo)
	{
		if (pthread_create(&obs->philos_t[i], NULL, (void *)philo_routines,
				(void *)&obs->philos[i]) != 0)
			return (0);
	}
	i = -1;
	obs->run = TRUE;
	obs->start_time = get_current_time();
	if (!obs->start_time)
		return (0);
	while (++i < obs->nb_philo)
		obs->philos[i].last_meal = obs->start_time;
	pthread_mutex_unlock(&obs->mtx_run);
	return (1);
}

int	main(int argc, char **argv)
{
	int		*tab_values;
	t_obs	*obs;
	t_uint	i;

	memset(&tab_values, 0, (sizeof(int *)));
	memset(&obs, 0, (sizeof(t_obs *)));
	if (argc < 5 || argc > 6)
		return (1);
	if (!check_args((argc - 1), ++argv, &tab_values))
		return (2);
	obs = build_obs(tab_values);
	free(tab_values);
	if (!obs)
		return (1);
	if (!start_threads(obs))
		return (1);
	i = -1;
	while (++i < obs->nb_philo)
		pthread_join(obs->philos_t[i], NULL);
	pthread_join(obs->obs_thread, NULL);
	destroy_all(&obs);
	return (0);
}
