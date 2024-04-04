/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_meals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:16:24 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/04 11:12:50 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_take_a_fork(t_philo *philo)
{
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;

	forkr = philo->forkl;
	forkl = &philo->forkr;
	if (philo->idx_philo % 2)
	{
		forkl = philo->forkl;
		forkr = &philo->forkr;
	}
	if (forkl == forkr)
	{
		philo_die(philo, calc_time_philo(philo));
		return (-1);
	}
	pthread_mutex_lock(forkr);
	print_action(philo, TAKE_FORK);
	pthread_mutex_lock(forkl);
	print_action(philo, TAKE_FORK);
	pthread_mutex_lock(philo->write);
	philo->status = TAKE_FORK;
	pthread_mutex_unlock(philo->write);
	check_time_actions(philo);
	return (0);
}

static int	check_meals_status(t_philo *philo)
{
	pthread_mutex_lock(philo->write);
	if (philo->status == DEAD)
	{
		pthread_mutex_unlock(philo->write);
		pthread_mutex_unlock(philo->forkl);
		pthread_mutex_unlock(&philo->forkr);
		return (-1);
	}
	pthread_mutex_unlock(philo->write);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	if (philo_take_a_fork(philo) == -1)
		return (-1);
	check_time_actions(philo);
	if (check_meals_status(philo) == -1)
		return (-1);
	philo->nbr_meals_count += 1;
	print_action(philo, EAT);
	pthread_mutex_lock(philo->write);
	if (philo->all_d_ph->nbr_of_meals != -1
		&& philo->nbr_meals_count >= philo->all_d_ph->nbr_of_meals)
		philo->status_meals = FULL_PHILO;
	pthread_mutex_unlock(philo->write);
	gettimeofday(&philo->ptime->start, NULL);
	pthread_mutex_lock(philo->write);
	philo->status = EAT;
	pthread_mutex_unlock(philo->write);
	check_time_actions(philo);
	usleep(philo->all_d_ph->time_to_eat * 1000);
	pthread_mutex_unlock(philo->forkl);
	pthread_mutex_unlock(&philo->forkr);
	return (0);
}
