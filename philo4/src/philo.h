/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:22:38 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/18 11:20:11 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# define NOTHING 0
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
	pthread_mutex_t	forkr;
	struct timeval	start_philo;
	struct timeval	end_philo;
	int				status;
	int				nbr_meals;
	int				i;
}				t_philo;

typedef struct s_data
{
	struct timeval	start;
	struct timeval	end;
	int				nbr_of_philo;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	int				nbr_of_meals;
	t_philo			**philo;
	int				finish;
	int				i;
}				t_data;

// actions.c
void	philo_eat(t_data *data);
void	philo_sleep(t_data *data);
void	philo_think(t_data *data);
void	first_part(t_data *data);
void	*life_philo(void *arg);
// check_arg.c
int	check_data(char **av);
int	check_arg(int ac, char **av);
// init_data.c
void	init_data(char **av, t_data *data);
void	init_forkl(t_data *data);
void	philo_init(t_data *data);
void	init_data_death(t_data *data);
void	init_forkr(t_data *data);
// philo.c
// timer.c
void	print_action(t_data *data, int i);
void	send_end_msg(t_data *data, int i);
void	check_time_actions(t_data *data);
void	*check_action(void *arg);
// utils.c
long long int	ft_atoll(char *nbr);
unsigned long long int	calc_time(t_data *data);
unsigned long long int	calc_time_philo(t_data *data);

/*a suppr*/
void	print_all(t_data *data);


#endif
