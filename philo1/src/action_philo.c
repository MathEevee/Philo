/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:31:16 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/25 15:29:21 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_die(t_philo *philo, long long int diff)
{
	long long int	time_to_die;
	
	time_to_die = philo->all_d_ph->time_to_die;
	usleep((time_to_die - diff));
	// pthread_mutex_lock(philo->write);
	philo->status = DEAD;
	print_action(philo, DEAD);
	// pthread_mutex_unlock(philo->write);
	// free(philo->write);
	// pthread_mutex_destroy(philo->write);
}

void	philo_take_a_fork(t_philo *philo, pthread_mutex_t *fork)
{
	// pthread_mutex_lock(philo->write);
	pthread_mutex_lock(fork);
	print_action(philo, TAKE_FORK);
	// pthread_mutex_unlock(philo->write);
}

void	philo_eat(t_philo *philo)
{
	philo_take_a_fork(philo, philo->forkl);
	philo_take_a_fork(philo, philo->forkr);
	// pthread_mutex_lock(philo->write);
	philo->nbr_meals_count += 1;
	print_action(philo, EAT);
	if (philo->nbr_meals_count >= philo->all_d_ph->nbr_of_meals)
		philo->status_meals = FULL_PHILO;
	// pthread_mutex_unlock(philo->write);
	usleep(philo->all_d_ph->time_to_eat * 1000);
	gettimeofday(&philo->ptime->start, NULL);
	pthread_mutex_unlock(philo->forkr);
	pthread_mutex_unlock(philo->forkl);
}

void	philo_sleep(t_philo *philo)
{
	// pthread_mutex_lock(philo->write);
	print_action(philo, SLEEP);
	// pthread_mutex_unlock(philo->write);
	usleep(philo->all_d_ph->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	// pthread_mutex_lock(philo->write);
	print_action(philo, THINK);
	// pthread_mutex_unlock(philo->write);
}
