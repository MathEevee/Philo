/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:58:05 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/16 16:06:24 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_time(t_data *data, int time)
{
	int	diff;
	
	gettimeofday(&data->philo[data->i]->end_philo, NULL);
	diff = &data->philo[data->i]->end_philo\
			- &data->philo[data->i]->start_philo;
	if (diff + time > data->time_to_die)
	{
		data->philo[data->i]->status = DEAD;
		data->finish = END;
		return (-1);
	}
	if (data->i % 3 == 2)
	{
		data->philo[data->i]->status = TAKE_FORK_R;
		pthread_mutex_lock(data->philo[data->i]->forkr);
		usleep(data->time_to_eat);
	}
	else if (data->i % 3 == 1)
	{
		data->philo[data->i]->status = TAKE_FORK_R;
		pthread_mutex_lock(data->philo[data->i]->forkr);
	}
	else
		data->philo[data->i]->status = THINK;
	return (0);
}

void	life_loop(t_data *data)
{
	gettimeofday(&data->philo[data->i]->end_philo, NULL);
	if (check_time(data, data->time_to_eat))
	{
		usleep(&data->time_to_die - &data->philo[data->i]->end_philo);
		data->philo[data->i]->status = DEAD;
		data->finish = END;
	}
	pthread_mutex_lock(data->philo[data->i]->forkl);
	data->philo[data->i]->status = EAT;
	usleep(data->time_to_eat);
	gettimeofday(&data->philo[data->i]->start_philo, NULL);
	pthread_mutex_unlock(data->philo[data->i]->forkl);
	pthread_mutex_unlock(data->philo[data->i]->forkr);
	data->philo[data->i]->status = SLEEP;
	usleep(data->time_to_sleep);
	pthread_mutex_lock(data->philo[data->i]->forkr);
	data->philo[data->i]->status = TAKE_FORK_R;
	usleep(data->time_to_eat);
	data->philo[data->i]->status = THINK;
}

void	first_part(t_data *data)
{
	gettimeofday(&data->philo[data->i]->start_philo, NULL);
	data->philo[data->i]->status = THINK;
	usleep(100);
	if (data->i % 3 == 0)
	{
		if (check_time(data, data->time_to_eat * 3) == -1)
		return ;
	}
	else if (data->i % 3 == 2)
	{
		if (check_time(data, data->time_to_eat * 2) == -1)
		return ;
	}
	else
	{
		if (check_time(data, data->time_to_eat) == -1)
		return ;
	}
}
/*	gettimeofday(&data->philo[data->i]->start_philo, NULL);
	usleep(100);
	if (data->i % 3 == 1)
		check_time(data, data->time_to_eat);
	else if (data->i % 3 == 2)
	{
		check_time(data, data->time_to_eat * 2);
		data->philo[data->i]->status = TAKE_FORK_R;
	}
	else
	{
		check_time(data, data->time_to_eat * 3);
		data->philo[data->i]->status = THINK;
	}
	
	
	
	struct timeval *diff;

	gettimeofday(&data->philo[data->i]->end_philo, NULL);
	diff = &data->philo[data->i]->end_philo -\
			&data->philo[data->i]->start_philo;
	if (diff > &data->time_to_die)
	{
		
	}
*/