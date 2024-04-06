/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:37:16 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/06 11:41:18 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	lock_fork(t_philo *philo, t_forks *forkl, t_forks *forkr)
{
	pthread_mutex_lock(philo->write);
	forkr->in_use = true;
	philo->status = TAKE_FORK;
	pthread_mutex_unlock(philo->write);
	print_action(philo, TAKE_FORK);
	pthread_mutex_lock(philo->write);
	forkl->in_use = true;
	philo->status = TAKE_FORK;
	pthread_mutex_unlock(philo->write);
	print_action(philo, TAKE_FORK);
	pthread_mutex_unlock(&forkl->mutex);
	pthread_mutex_unlock(&forkr->mutex);
}

static int	check_take_fork(t_forks *forkr, t_forks *forkl, t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&forkl->mutex);
		pthread_mutex_lock(&forkr->mutex);
		check_time_actions(philo);
		pthread_mutex_lock(philo->write);
		if (philo->status == DEAD)
		{
			pthread_mutex_unlock(philo->write);
			pthread_mutex_unlock(&forkl->mutex);
			pthread_mutex_unlock(&forkr->mutex);
			return (-1);
		}
		pthread_mutex_unlock(philo->write);
		if (forkr->in_use == false && forkl->in_use == false)
		{
			lock_fork(philo, forkl, forkr);
			return (0);
		}
		pthread_mutex_unlock(&forkl->mutex);
		pthread_mutex_unlock(&forkr->mutex);
		usleep(10);
	}
}

void	delock_fork(t_philo *philo)
{
	t_forks	*forkl;
	t_forks	*forkr;

	if (philo->idx % 2)
	{
		forkl = philo->forkl;
		forkr = &philo->forkr;
	}
	else
	{
		forkr = philo->forkl;
		forkl = &philo->forkr;
	}
	pthread_mutex_lock(&forkl->mutex);
	pthread_mutex_lock(&forkr->mutex);
	forkl->in_use = false;
	forkr->in_use = false;
	pthread_mutex_unlock(&forkl->mutex);
	pthread_mutex_unlock(&forkr->mutex);
}

int	philo_take_a_fork(t_philo *philo)
{
	t_forks	*forkl;
	t_forks	*forkr;

	if (philo->idx % 2)
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
	if (check_take_fork(forkr, forkl, philo) == -1)
		return (-1);
	return (0);
}
