/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:06:12 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/21 09:59:19 by matde-ol         ###   ########.fr       */
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
# define TAKE_FORK_L 2
# define EAT 3
# define SLEEP 4
# define THINK 5
# define DEAD 6
# define FULL 7
# define MS_TO_SEC 1000000
# define LOOP 1
# define END 2
# define YES 1
# define NO 2

typedef struct s_philo
{
	struct timeval	start_philo;
	struct timeval	end_philo;
	pthread_t		philosopher;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	int				status;
	long long int	nbr_of_meals_total;
	int				nbr_meals_count;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	time_to_die;
	int				idx_philo;
	int				loop;
	int				print;
	pthread_mutex_t	*write;
}				t_philo;

typedef struct s_checker
{
	struct timeval	start;
	struct timeval	end;
	int				nbr_of_philo;
	int				finish;
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
void	check_life(t_philo **philo, t_checker *checker);
/*clear.c*/
void clear_stop(t_philo **philo, t_checker *checker, int i);
void	free_philo(t_philo **philo);
/*philo_create.c*/
t_philo	**philo_init(t_checker *checker, char **av);
/*print.c*/
void	print_action(t_checker *checker, int i, t_philo *philo);
void	end_message(t_philo **philo, t_checker *checker, int nbr_of_philo_full);
/*simulation.c*/
void	start_simulation(t_philo **philo, t_checker *checker);
/*utils.c*/
long long int	ft_atoll(char *nbr);
unsigned long long int	calc_time(t_checker *checker);
unsigned long long int	calc_time_philo(t_philo *philo);

/*suppresion*/
void	print_all(t_checker *checker, t_philo **philo);


#endif
