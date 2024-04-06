/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_meals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:37:06 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/06 11:41:43 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_eat_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->write);
	if (philo->status == DEAD)
	{
		pthread_mutex_unlock(philo->write);
		return (-1);
	}
	pthread_mutex_unlock(philo->write);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	usleep(100);
	if (philo_take_a_fork(philo) == -1)
		return (-1);
	print_action(philo, EAT);
	check_time_actions(philo);
	if (check_eat_philo(philo) == -1)
		return (-1);
	philo->nbr_meals_count += 1;
	if (philo->all_d_ph->nbr_of_meals != -1
		&& philo->nbr_meals_count >= philo->all_d_ph->nbr_of_meals)
	{
		pthread_mutex_lock(philo->write);
		philo->status_meals = FULL_PHILO;
		pthread_mutex_unlock(philo->write);
	}
	gettimeofday(&philo->ptime->start, NULL);
	usleep(philo->all_d_ph->time_to_eat * 1000);
	delock_fork(philo);
	return (0);
}
