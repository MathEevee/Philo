/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:20:09 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/19 16:37:38 by matde-ol         ###   ########.fr       */
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

t_philo	**philo_init(t_checker *checker)
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
	return (philo);
}
