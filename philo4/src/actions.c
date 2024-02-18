/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:08:23 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/18 17:02:47 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_data *data)
{
	pthread_mutex_lock(&data->philo[data->i].forkl);
	data->philo[data->i].status = EAT;
	usleep(data->time_to_eat);
	gettimeofday(&data->philo[data->i].start_philo, NULL);
	pthread_mutex_unlock(&data->philo[data->i].forkr);
	pthread_mutex_unlock(&data->philo[data->i].forkl);
}

void	philo_sleep(t_data *data)
{
	data->philo[data->i].status = SLEEP;
	usleep(data->time_to_sleep);
}

void	philo_think(t_data *data)
{
	data->philo[data->i].status = THINK;
	pthread_mutex_lock(&data->philo[data->i].forkr);
	data->philo[data->i].status = TAKE_FORK_R;
}

void	first_part(t_data *data)
{
	data->philo[data->i].status = THINK;
	check_time_actions(data);
	if (data->i % 3 == 1)
	{
		philo_think(data);
		philo_eat(data);
	}
	else if (data->i % 3 == 2)
		philo_think(data);
	else
	{
		usleep(data->time_to_eat);
		philo_think(data);
	}
}

void	*life_philo(void *arg)
{
	t_data *data;

	data = (t_data *) arg;
	gettimeofday(&data->philo[data->i].start_philo, NULL);
	first_part(data);
	while(data->finish == LOOP)
	{
		check_time_actions(data);
		philo_eat(data);
		philo_think(data);
		philo_sleep(data);
	}
	return (NULL);
}
