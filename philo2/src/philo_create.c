/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:10:02 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/22 16:08:08 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void init_forkl(t_philo **philo, t_checker *checker)
{
	int	i;

	i = 0;
	while (i < checker->nbr_of_philo)
	{
		if (i == 0)
			philo[i]->forkl = philo[checker->nbr_of_philo - 1]->forkr;
		else
			philo[i]->forkl = philo[i - 1]->forkr;
		printf("philo[%d]->forkl < %p\n", i ,philo[i]->forkl);
		i++;
	}
}


static void	init_forkr(t_philo *philo)
{
	pthread_mutex_t	*forkr;
	
	forkr = malloc(sizeof(pthread_mutex_t));
	philo->forkr = forkr;
	pthread_mutex_init(philo->forkr, NULL);
}

static void	init_value_philo(t_philo *philo, char **av, int i)
{
	philo->nbr_meals_count = 0;
	philo->status = THINK;
	philo->status_meals = NO;
	philo->idx_philo = i;
	philo->time_to_die = ft_atoll(av[2]);
	philo->time_to_eat = ft_atoll(av[3]);
	philo->time_to_sleep = ft_atoll(av[4]);
	philo->nbr_of_meals_total = ft_atoll(av[5]);
	init_forkr(philo);
}

t_philo	**philo_init(t_checker *checker, char **av)
{
	int				i;
	t_philo			**philo;
	pthread_mutex_t	*write;

	i = 0;
	checker->finish = LOOP;
	gettimeofday(&checker->start, NULL);
	write = malloc(sizeof(pthread_mutex_t));
	philo = malloc(sizeof(t_philo) * (checker->nbr_of_philo + 1));
	//protec
	while (i < checker->nbr_of_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		//protec
		init_value_philo(philo[i], av, i);
		philo[i]->write = write;
		// printf("philo[%d]->forkr > %p\n", i ,philo[i]->forkr);
		i++;
	}
	pthread_mutex_init(write, NULL);
	init_forkl(philo, checker);
	printf("%d\n", i);
	// print_all(checker, philo);
	return (philo);
}
