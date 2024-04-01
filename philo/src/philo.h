/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:06:12 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/01 21:41:52 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
#include <stdbool.h>
# define SEC_MS 1000000
# define MS_USEC 1000
# define LOOP 1
# define END 2
# define FULL_PHILO 3
# define DEAD 6
# define NOTHING 1
# define TAKE_FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4

typedef struct s_times_philo
{
	struct timeval	start;
	struct timeval	end;
}			t_times_philo;

typedef struct s_data_simulation
{
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	time_to_die;
	int				nbr_of_meals;
	t_times_philo	*gtimer;
}			t_data_simulation;

typedef struct s_philo
{
	t_times_philo		*ptime;
	t_data_simulation	*all_d_ph;
	pthread_t			philosopher;
	pthread_mutex_t		*forkl;
	pthread_mutex_t		forkr;
	pthread_mutex_t		*write;
	int					nbr_meals_count;
	int					status;
	int					status_meals;
	int					idx_philo;
	int					loop;
}				t_philo;

typedef struct s_checker
{
	long long int	nbr_of_philo;
	int				status_finish;
}				t_checker;

/*action_philo.c*/
int		philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_die(t_philo *philo, long long int diff);
/*check_arg.c*/
int		check_arg(int ac, char **av);
/*check_life_philo.c*/
void	check_time_actions(t_philo *philo);
void	check_life(t_philo **philo, t_checker checker,
			t_data_simulation *d_sim);
/*clear.c*/
void	free_philo(t_philo **philo);
void	set_end(t_philo **philo, t_checker checker);
void	clear_stop(t_philo **philo, t_checker checker);
void	data_clear(t_data_simulation *d_sim);
/*philo_create.c*/
int		init_philo(t_philo **philo, t_checker checker,
			t_data_simulation *d_sim);
/*print.c*/
void	print_action(t_philo *philo, int status);
void	end_message(t_philo **philo, t_checker checker,
			t_data_simulation *d_sim);
/*routine.c*/
int		philo_routine(t_philo *philo);
void	*life_philo(void *arg);
/*start_simlation.c*/
int		begin_simulation(char *av, t_data_simulation *data_sim);
/*utils.c*/
ssize_t	ft_atoll(char *nbr);
size_t	calc_time(t_data_simulation *d_sim);
size_t	calc_time_philo(t_philo *philo);

#endif
