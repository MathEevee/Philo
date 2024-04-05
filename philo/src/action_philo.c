/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:31:16 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/05 12:33:04 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_die(t_philo *philo, long long int diff)
{
	long long int	time_to_die;
	long long int	time_to_eat;

	time_to_die = philo->all_d_ph->time_to_die;
	time_to_eat = philo->all_d_ph->time_to_eat;
	if (time_to_die < time_to_eat)
		usleep(time_to_die - diff * 1000);
	else if (time_to_die - diff > 0)
		usleep((time_to_die - diff) * 1000);
	print_action(philo, DEAD);
	pthread_mutex_lock(philo->write);
	philo->status = DEAD;
	pthread_mutex_unlock(philo->write);
}

void	philo_think(t_philo *philo)
{
	print_action(philo, THINK);
	pthread_mutex_lock(philo->write);
	philo->status = THINK;
	pthread_mutex_unlock(philo->write);
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, SLEEP);
	pthread_mutex_lock(philo->write);
	philo->status = SLEEP;
	pthread_mutex_unlock(philo->write);
	usleep(philo->all_d_ph->time_to_sleep * 1000);
}
