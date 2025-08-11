/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:02:40 by benjamsc          #+#    #+#             */
/*   Updated: 2025/07/12 17:12:51 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_routine(t_philo *philo, char type)
{
	t_uint	t;

	pthread_mutex_lock(&philo->data_obs->mtx_disp);
	t = get_current_time() - philo->data_obs->start_time;
	if (type == FORK)
		printf("%s%u %d has taken a fork%s\n", CYAN, t, philo->id + 1, RESET);
	if (type == EAT)
		printf("%s%u %d is eating%s\n", BLUE, t, philo->id + 1, RESET);
	if (type == SLEEP)
		printf("%s%u %d is sleeping%s\n", MAGENTA, t, philo->id + 1, RESET);
	if (type == THINK)
		printf("%s%u %d is thinking%s\n", YELLOW, t, philo->id + 1, RESET);
	if (type == DEAD)
		printf("%s%u %d died%s\n", RED, t, philo->id + 1, RESET);
	pthread_mutex_unlock(&philo->data_obs->mtx_disp);
	return (1);
}

void	wait_for(t_philo *philo, char type)
{
	t_uint	t;

	t = 0;
	if (type == EAT)
		t = philo->data_obs->time_to_eat;
	else if (type == SLEEP)
		t = philo->data_obs->time_to_sleep;
	else if (type == THINK)
		t = 1;
	usleep(t * 1000);
}

void	good_one(t_philo *p, pthread_mutex_t **f, pthread_mutex_t **s)
{
	if (p->id % 2 == 0)
	{
		*f = p->r_fork;
		*s = p->l_fork;
	}
	else
	{
		*f = p->l_fork;
		*s = p->r_fork;
	}
}

int	is_running(t_philo *philo)
{
	pthread_mutex_lock(&philo->data_obs->mtx_run);
	if (philo->data_obs->run == FALSE)
	{
		return (pthread_mutex_unlock(&philo->data_obs->mtx_run), 0);
	}
	pthread_mutex_unlock(&philo->data_obs->mtx_run);
	return (1);
}

int	loop_needed(t_philo *philo)
{
	if (philo->data_obs->nb_loop == -1)
		return (1);
	else if (philo->loop_count < philo->data_obs->nb_loop)
		return (1);
	return (0);
}
