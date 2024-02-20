/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:10:02 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/20 18:25:51 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void init_forkl(int i, t_philo **philo)
{
	philo[0]->forkl = philo[i - 1]->forkr;
	while (i >= 0)
	{
		philo[i - 1]->forkl = philo[i - 2]->forkl;
		printf("philo[%d]->forkl < %p\n", i ,philo[i]->forkl);
		printf("philo[%d]->forkr > %p\n", i ,philo[i]->forkr);
		i--;
	}
}

static void	init_forkr(int i, t_philo **philo)
{
	pthread_mutex_t	*forkr;
	
	forkr = malloc(sizeof(pthread_mutex_t));
	philo[i]->forkr = forkr;
	pthread_mutex_init(philo[i]->forkr, NULL);
}

// static void init_forkl(int i, t_philo **philo, t_checker *checker)
// {
// 	pthread_mutex_t	forkl;
	
// 	if (i == 0)
// 		return ;
// 	pthread_mutex_init(&forkl, NULL);
// 	if (i == checker->nbr_of_philo - 1)
// 	{
// 		philo[i]->forkl = philo[0]->forkr;
// 		return ;
// 	}
// 	forkl = philo[i - 1]->forkr;
// 	philo[i]->forkl = forkl;
// }

// static void	init_forkr(int i, t_philo **philo, t_checker *checker)
// {
// 	pthread_mutex_t	forkr;
	
// 	pthread_mutex_init(&forkr, NULL);
// 	philo[i]->forkr = forkr;
// 	init_forkl(i, philo, checker);
// }

t_philo	**philo_init(t_checker *checker, char **av)
{
	int				i;
	t_philo			**philo;

	i = 0;
	checker->finish = LOOP;
	gettimeofday(&checker->start, NULL);
	philo = malloc(sizeof(t_philo) * (checker->nbr_of_philo + 1));
	//protec
	while (i < checker->nbr_of_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		//protec
		philo[i]->nbr_meals_count = 0;
		philo[i]->status = THINK;
		philo[i]->idx_philo = i;
		philo[i]->time_to_die = ft_atoll(av[2]);
		philo[i]->time_to_eat = ft_atoll(av[3]);
		philo[i]->time_to_sleep = ft_atoll(av[4]);
		philo[i]->nbr_of_meals_total = ft_atoll(av[5]);
		init_forkr(i, philo);
		printf("philo[%d]->forkr > %p\n", i ,philo[i]->forkr);
		i++;
	}
	init_forkl(i, philo);
	// print_all(checker, philo);
	return (philo);
}
