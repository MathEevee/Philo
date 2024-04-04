/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_meals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:37:06 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/04 12:34:35 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_take_a_fork(t_philo *philo)
{
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;

	if (philo->idx_philo % 2)
	{
		forkl = philo->forkl;
		forkr = &philo->forkr;
	}
	else
	{
		forkr = philo->forkl;
		forkl = &philo->forkr;
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
	return (0);
}

static int	check_eat_philo(t_philo *philo)
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
	if (check_eat_philo(philo) == -1)
		return (-1);
	philo->nbr_meals_count += 1;
	print_action(philo, EAT);
	pthread_mutex_lock(philo->write);
	philo->status = EAT;
	pthread_mutex_unlock(philo->write);
	check_time_actions(philo);
	if (philo->all_d_ph->nbr_of_meals != -1
		&& philo->nbr_meals_count >= philo->all_d_ph->nbr_of_meals)
		philo->status_meals = FULL_PHILO;
	gettimeofday(&philo->ptime->start, NULL);
	usleep(philo->all_d_ph->time_to_eat * 1000);
	pthread_mutex_unlock(philo->forkl);
	pthread_mutex_unlock(&philo->forkr);
	return (0);
}
