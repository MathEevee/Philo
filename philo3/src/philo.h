/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:22:38 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/19 16:45:23 by matde-ol         ###   ########.fr       */
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

/*init_philo.c*/
t_philo	**philo_init(t_checker *checker);
/*check_arg.c*/
int	check_arg(int ac, char **av);



#endif
