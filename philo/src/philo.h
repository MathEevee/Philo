/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:06:12 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/05 13:56:52 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdbool.h>

# define SEC_MS 1000000
# define MS_USEC 1000

enum e_status {
	LOOP,
	END,
	FULL_PHILO,
	DEAD,
	TAKE_FORK,
	EAT,
	SLEEP,
	THINK,
};

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

typedef struct s_forks
{
	bool			in_use;
	pthread_mutex_t	mutex;
}			t_forks;

typedef struct s_philo
{
	t_times_philo		*ptime;
	t_data_simulation	*all_d_ph;
	pthread_t			philosopher;
	pthread_mutex_t		*write;
	t_forks				*forkl;
	t_forks				forkr;
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
void	philo_think(t_philo *philo);
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
/*take_fork.c*/
int		philo_take_a_fork(t_philo *philo);
void	delock_fork(t_philo *philo);

#endif
