/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:10:36 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/06 11:41:18 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	first_part(t_philo *philo)
{
	philo_think(philo);
	if ((philo->idx + 1) % 2 == 0)
		usleep(500);
}

int	get_philo_status(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(philo->write);
	res = philo->status;
	pthread_mutex_unlock(philo->write);
	return (res);
}

int	philo_routine(t_philo *philo)
{
	check_time_actions(philo);
	if (get_philo_status(philo) == DEAD || get_philo_status(philo) == END)
		return (-1);
	if (philo_eat(philo) == -1)
		return (-1);
	check_time_actions(philo);
	if (get_philo_status(philo) == DEAD || get_philo_status(philo) == END)
		return (-1);
	philo_sleep(philo);
	check_time_actions(philo);
	if (get_philo_status(philo) == DEAD || get_philo_status(philo) == END)
		return (-1);
	pthread_mutex_lock(philo->write);
	if (philo->status_meals == FULL_PHILO || philo->status == END)
	{
		pthread_mutex_unlock(philo->write);
		return (-1);
	}
	pthread_mutex_unlock(philo->write);
	return (0);
}

void	*life_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	philo->loop = LOOP;
	gettimeofday(&philo->ptime->start, NULL);
	check_time_actions(philo);
	first_part(philo);
	while (philo->status_meals == LOOP)
	{
		if (philo_routine(philo) == -1)
			break ;
		philo_think(philo);
	}
	return (NULL);
}
