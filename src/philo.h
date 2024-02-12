/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:26:25 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/12 15:29:04 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		philosopher;
	pthread_mutex_t	forkl;
	pthread_mutex_t	forkr;
}				t_philo;

typedef struct s_data
{
	struct timeval	start;
	struct timeval	end;
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	t_philo			**philo;
}				t_data;

/*check_arg.c*/
int		check_arg(int ac, char **av);
int		check_data(char **av);
/*init_data.c*/
void	init_data(char **av, t_data *data);
/*utils.c*/
int		ft_atoll(char *nbr);

#endif
