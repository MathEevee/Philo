/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:08:23 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/20 15:01:13 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo[philo->index_of_philo].forkl);
	philo[philo->index_of_philo].status = EAT;
	philo[philo->index_of_philo].nbr_meals++;
	usleep(philo[philo->index_of_philo].time_to_eat);
	gettimeofday(&philo[philo->index_of_philo].start_philo, NULL);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_unlock(&philo[philo->index_of_philo].forkr);
	pthread_mutex_unlock(&philo[philo->index_of_philo].forkl);
	philo[philo->index_of_philo].status = SLEEP;
	usleep(philo[philo->index_of_philo].time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	philo[philo->index_of_philo].status = THINK;
	usleep(100);
	pthread_mutex_lock(&philo[philo->index_of_philo].forkr);
	philo[philo->index_of_philo].status = TAKE_FORK_R;
}

void	first_part(t_philo *philo)
{
	philo[philo->index_of_philo].status = THINK;
	usleep(100);
	check_time_actions(philo);
	if (philo[philo->index_of_philo].index_of_philo % 2 == 1)
	{
		philo_think(philo);
		philo_eat(philo);
	}
	else if (philo[philo->index_of_philo].index_of_philo % 3 == 2)
		philo_think(philo);
	else
	{
		usleep(100);
		philo_think(philo);
	}
}

void	*life_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	philo[philo->index_of_philo].loop = LOOP;
	gettimeofday(&philo[philo->index_of_philo].start_philo, NULL);
	first_part(philo);
	while (philo[philo->index_of_philo].loop == LOOP)
	{
		check_time_actions(philo);
		philo_eat(philo);
		check_time_actions(philo);
		philo_sleep(philo);
		check_time_actions(philo);
		philo_think(philo);
	}
	return (NULL);
}
