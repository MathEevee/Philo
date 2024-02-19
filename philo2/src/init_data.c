/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:31:40 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/19 15:43:59 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(char **av, t_checker *checker)
{
	checker->nbr_of_philo = ft_atoll(av[1]);
	checker->time_to_die = ft_atoll(av[2]);
	checker->time_to_eat = ft_atoll(av[3]);
	checker->time_to_sleep = ft_atoll(av[4]);
	checker->nbr_of_meals = ft_atoll(av[5]);
}

void init_forkl(int i, t_philo **philo, t_checker *checker)
{
	pthread_mutex_t	forkl;
	
	// if (i == 0)
	// 	return ;
	// pthread_mutex_init(&forkl, NULL);
	// if (i == checker->nbr_of_philo - 1)
	// {
	// 	philo[i]->forkl = philo[0]->forkr;
	// 	return ;
	// }
	// forkl = philo[i - 1]->forkr;
	// philo[i]->forkl = forkl;
}

void	init_forkr(int i, t_philo **philo, t_checker *checker)
{
	pthread_mutex_t	forkr;
	
	pthread_mutex_init(&forkr, NULL);
	philo[i]->forkr = forkr;
	init_forkl(i, philo, checker);
}

void	**philo_init(t_checker *checker)
{
	int				i;
	t_philo			**philo;

	i = 0;
	checker->finish = LOOP;
	philo = malloc(sizeof(t_philo) * (checker->nbr_of_philo));
	while (i <= checker->nbr_of_philo - 1)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->nbr_meals = 0;
		philo[i]->status = NOTHING;
		philo[i]->index_of_philo = i;
		init_forkr(i, philo, checker);
		i++;
	}
}

void	init_data_death(t_checker *checker)
{
	// checkerphilo[checker->i].status = DEAD;
	// checker->finish = END;
}
