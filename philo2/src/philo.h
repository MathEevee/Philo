/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:26:25 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/17 10:01:44 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# define TAKE_FORK_L 1
# define TAKE_FORK_R 2
# define EAT 3
# define SLEEP 4
# define THINK 5
# define DEAD 6
# define FULL 7
# define MS_TO_SEC 1000000
# define LOOP 1
# define END 2

typedef struct s_philo
{
	pthread_t		philosopher;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	struct timeval	start_philo;
	struct timeval	end_philo;
	int				status;
	int				nbr_meals;
}				t_philo;

typedef struct s_data
{
	struct timeval	start;
	struct timeval	end;
	int				nbr_of_philo;
	unsigned long long int				time_to_die;
	unsigned long long int				time_to_eat;
	unsigned long long int				time_to_sleep;
	int				nbr_of_meals;
	int				i;
	t_philo			**philo;
	int				finish;
}				t_data;

// actions.c
int	check_time(t_data *data, unsigned long long int time);
void	life_loop(t_data *data);
void	first_part(t_data *data);
// check_arg.c
static int	check_is_digit(char **av);
static int	check_arg_nbr(int ac);
int	check_data(char **av);
int	check_arg(int ac, char **av);
// init_data.c
void	init_data(char **av, t_data *data);
// philo.c
// print_conditions.c
void	print_condition(t_data *data);
void	conditions_primary_actions(t_data *data);
void	conditions_end(t_data *data);
void	conditions_others(t_data *data);
// simulation.c
int life_philo(t_data *data);
void init_forkl(t_data *data);
void philo_init(t_data *data, t_philo **philo);
// timer.c
void	timer_to_life(t_data *data);
// utils.c
int	ft_atoll(char *nbr);
unsigned long long int	calc_time(t_data *data);

#endif
