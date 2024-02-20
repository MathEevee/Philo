/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:10:02 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/20 15:48:40 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void init_forkl(int i, t_philo **philo, t_checker *checker)
{
	pthread_mutex_t	forkl;
	
	if (i == 0)
		return ;
	pthread_mutex_init(&forkl, NULL);
	if (i == checker->nbr_of_philo - 1)
	{
		philo[i]->forkl = philo[0]->forkr;
		return ;
	}
	forkl = philo[i - 1]->forkr;
	philo[i]->forkl = forkl;
}

static void	init_forkr(int i, t_philo **philo, t_checker *checker)
{
	pthread_mutex_t	forkr;
	
	pthread_mutex_init(&forkr, NULL);
	philo[i]->forkr = forkr;
	init_forkl(i, philo, checker);
}

t_philo	**philo_init(t_checker *checker, char **av)
{
	int				i;
	t_philo			**philo;

	i = 0;
	checker->finish = LOOP;
	gettimeofday(&checker->start, NULL);
	philo = malloc(sizeof(t_philo) * (checker->nbr_of_philo));
	//protec
	while (i <= checker->nbr_of_philo - 1)
	{
		philo[i] = malloc(sizeof(t_philo));
		//protec
		philo[i]->nbr_meals_count = 0;
		philo[i]->status = NOTHING;
		philo[i]->idx_philo = i;
		philo[i]->time_to_die = ft_atoll(av[2]);
		philo[i]->time_to_eat = ft_atoll(av[3]);
		philo[i]->time_to_sleep = ft_atoll(av[4]);
		philo[i]->nbr_of_meals_total = ft_atoll(av[5]);
		init_forkr(i, philo, checker);
		i++;
	}
	print_all(checker, philo);
	philo[i] = NULL;
	return (philo);
}
