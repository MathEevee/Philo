/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:31:16 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/01 22:14:08 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_die(t_philo *philo, long long int diff)
{
	long long int	time_to_die;

	time_to_die = philo->all_d_ph->time_to_die;
	// if (time_to_die < philo->all_d_ph->time_to_eat)
	// 	usleep(time_to_die * 1000);
	// else if (time_to_die < philo->all_d_ph->time_to_sleep)
	// 	usleep(time_to_die * 1000);
	if (time_to_die - diff > 0)
		usleep((time_to_die - diff) * 1000);
	print_action(philo, DEAD);
	pthread_mutex_lock(philo->write);
	philo->status = DEAD;
	pthread_mutex_unlock(philo->write);
}

// static int	philo_take_a_fork(t_philo *philo)
// {
// 	pthread_mutex_t	*forkl;
// 	pthread_mutex_t	*forkr;

// 	if (philo->idx_philo % 2)
// 	{
// 		forkl = philo->forkl;
// 		forkr = &philo->forkr;
// 	}
// 	else
// 	{
// 		forkr = philo->forkl;
// 		forkl = &philo->forkr;
// 	}
// 	if (forkl == forkr)
// 	{
// 		philo_die(philo, calc_time_philo(philo));
// 		return (-1);
// 	}
// 	pthread_mutex_lock(forkr);
// 	print_action(philo, TAKE_FORK);
// 	pthread_mutex_lock(forkl);
// 	print_action(philo, TAKE_FORK);
// 	return (0);
// }

// int	philo_eat(t_philo *philo)
// {
// 	if (philo_take_a_fork(philo) == -1)
// 		return (-1);
// 	check_time_actions(philo);
// 	pthread_mutex_lock(philo->write);
// 	if (philo->status == DEAD)
// 	{
// 		pthread_mutex_unlock(philo->write);
// 		pthread_mutex_unlock(philo->forkl);
// 		pthread_mutex_unlock(&philo->forkr);
// 		return (-1);
// 	}
// 	pthread_mutex_unlock(philo->write);
// 	philo->nbr_meals_count += 1;
// 	print_action(philo, EAT);
// 	pthread_mutex_lock(philo->write);
// 	philo->status = EAT;
// 	if (philo->all_d_ph->nbr_of_meals != -1
// 		&& philo->nbr_meals_count >= philo->all_d_ph->nbr_of_meals)
// 		philo->status_meals = FULL_PHILO;
// 	pthread_mutex_unlock(philo->write);
// 	gettimeofday(&philo->ptime->start, NULL);
// 	usleep(philo->all_d_ph->time_to_eat * 1000);
// 	pthread_mutex_unlock(philo->forkl);
// 	pthread_mutex_unlock(&philo->forkr);
// 	return (0);
// }

void	philo_sleep(t_philo *philo)
{
	print_action(philo, SLEEP);
	pthread_mutex_lock(philo->write);
	philo->status = SLEEP;
	pthread_mutex_unlock(philo->write);
	usleep(philo->all_d_ph->time_to_sleep * 1000);
}
