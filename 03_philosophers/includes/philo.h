/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:02:02 by benjamsc          #+#    #+#             */
/*   Updated: 2025/07/12 17:12:47 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// value
# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define SIZE_MAX 4294967295
# define FORK 'F'
# define F_FORK 'f'
# define S_FORK 's'
# define SLEEP 'S'
# define THINK 'T'
# define DEAD 'D'
# define EAT 'E'
# define INIT 'I'
// colors
# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

// typedef
typedef unsigned long	t_ulong;
typedef unsigned int	t_uint;
typedef int				t_bool;
typedef pthread_mutex_t	t_mtx;

typedef struct s_obs	t_obs;

typedef struct s_philo
{
	int					id;
	int					last_meal;
	int					loop_count;
	t_mtx				*l_fork;
	t_mtx				*r_fork;
	t_obs				*data_obs;
}						t_philo;

typedef struct s_obs
{
	t_uint				nb_philo;
	t_uint				time_to_die;
	t_uint				time_to_eat;
	t_uint				time_to_sleep;
	int					nb_loop;
	int					*jobs_done;
	t_bool				run;
	t_uint				start_time;
	int					mtx_count;
	t_mtx				mtx_run;
	t_mtx				mtx_disp;
	t_mtx				*mtx_forks;
	t_philo				*philos;
	pthread_t			obs_thread;
	pthread_t			*philos_t;
}						t_obs;

// checker
int						check_args(int argc, char **argv, int **tab_out);
// utils.c
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
int						ft_atoi(char *nptr);
long					ft_atol(char *nptr);
// geters.c
int						get_next_fork_id(t_obs *obs, int i);
t_uint					get_current_time(void);

// routines
void					*philo_routines(void *ptr_philo);
void					*obs_routines(void *ptr_obs);

// routines utils
int						print_routine(t_philo *philo, char type);
void					wait_for(t_philo *philo, char type);
void					good_one(t_philo *p, pthread_mutex_t **f,
							pthread_mutex_t **s);
int						is_running(t_philo *philo);
int						loop_needed(t_philo *philo);

// obs.c
int						all_eaten(t_obs *obs);
void					*obs_routines(void *ptr_obs);

void					unlock_forks(pthread_mutex_t **f, pthread_mutex_t **s);
void					destroy_all(t_obs **ptr_obs);
void					*case_only_one(t_philo *philo);

#endif
