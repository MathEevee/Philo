/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:31:16 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/22 16:15:28 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_die(t_philo *philo, long long int diff)
{
	long long int	time_to_die;
	
	time_to_die = philo->time_to_die;
	usleep(time_to_die - diff);
	philo->status = DEAD;
	philo->print = YES;
}

void	philo_eat(t_philo *philo)
{
	philo->status = TAKE_FORK;
	pthread_mutex_lock(philo->forkl);
	pthread_mutex_lock(philo->forkr);
	philo->status = EAT;
	philo->print = YES;
	philo->nbr_meals_count++;
	if (philo->nbr_meals_count >= philo->nbr_of_meals_total)
		philo->status_meals = FULL_MEALS;
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->forkr);
	pthread_mutex_unlock(philo->forkl);
	gettimeofday(&philo->start_philo, NULL);
}

void	philo_sleep(t_philo *philo)
{
	philo->status = SLEEP;
	philo->print = YES;
	usleep(philo->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	philo->status = THINK;
	philo->print = YES;
	usleep(1000);
}
