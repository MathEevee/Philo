/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:22:38 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/19 15:44:16 by matde-ol         ###   ########.fr       */
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
# define TAKE_FORK_R 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DEAD 5
# define FULL 6
# define MS_TO_SEC 1000000
# define LOOP 1
# define END 2

typedef struct s_philo
{
	struct timeval	start_philo;
	struct timeval	end_philo;
	pthread_t		philosopher;
	pthread_mutex_t	forkl;
	pthread_mutex_t	forkr;
	struct timeval	start_timer;
	struct timeval	end_timer;
	int				status;
	int				nbr_meals_full;
	int				nbr_meals;
	int				index_of_philo;
	int				print;
}				t_philo;

typedef struct s_checker
{
	struct timeval	start;
	struct timeval	end;
	int				nbr_of_philo;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	int				nbr_of_meals;
	int				finish;
}				t_checker;

// actions.c
void	philo_eat(t_checker *checker);
void	philo_sleep(t_checker *checker);
void	philo_think(t_checker *checker);
void	first_part(t_checker *checker);
void	*life_philo(void *arg);
// check_arg.c
int	check_data(char **av);
int	check_arg(int ac, char **av);
// init_data.c
void	**init_data(char **av, t_checker *checker);
void	init_forkl(int i, t_philo **philo, t_checker *checker);
void	**philo_init(t_checker *checker);
void	init_data_death(t_checker *checker);
void	init_forkr(int i, t_philo **philo, t_checker *checker);
// philo.c
// timer.c
void	print_action(t_checker *checker, int i);
void	send_end_msg(t_checker *checker, int i);
void	check_time_actions(t_checker *checker);
void	*check_action(void *arg);
// utils.c
long long int	ft_atoll(char *nbr);
unsigned long long int	calc_time(t_checker *checker);
unsigned long long int	calc_time_philo(t_checker *checker);

/*a suppr*/
void	print_all(t_checker *checker, t_philo **philo);


#endif
