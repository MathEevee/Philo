/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:06:12 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/27 10:57:01 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# define SEC_MS 1000000
# define MS_USEC 1000
# define LOOP 1
# define END 2
# define FULL_PHILO 3
# define DEAD 6
# define NOTHING 1
# define TAKE_FORK 1
// # define TAKE_FORK_R 2
# define EAT 3
# define SLEEP 4
# define THINK 5

typedef struct s_times_philo
{
	struct timeval	start;
	struct timeval	end;
}			t_times_philo;

typedef struct	s_data_simulation
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
	t_data_simulation 	*all_d_ph;
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
void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_die(t_philo *philo, long long int diff);
/*check_arg.c*/
int		check_arg(int ac, char **av);
/*check_life_philo.c*/
void	check_time_actions(t_philo *philo);
void	check_life(t_philo **philo, t_checker checker, t_data_simulation *d_sim);
void	start_simulation_philo(t_philo **philo, t_checker checker, t_data_simulation *d_sim);
/*clear.c*/
void	free_philo(t_philo **philo);
void	set_end(t_philo **philo, t_checker checker);
void clear_stop(t_philo **philo, t_checker checker);
/*philo_create.c*/
int	init_philo(t_philo **philo, t_checker checker, t_data_simulation *d_sim);
/*print.c*/
void	print_action(t_philo *philo, int status);
void	end_message(t_philo **philo, t_checker checker);
/*simulation.c*/
int	begin_simulation(char *av, t_data_simulation *data_sim);
void	start_simulation_philo(t_philo **philo, t_checker checker, t_data_simulation *d_sim);
/*utils.c*/
long long int	ft_atoll(char *nbr);
unsigned long long int	calc_time(t_data_simulation *d_sim);
unsigned long long int	calc_time_philo(t_philo *philo);


/*suppresion*/
void	print_all(t_checker checker, t_philo **philo);


#endif
