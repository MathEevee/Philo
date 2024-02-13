/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:34:13 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/13 14:59:40 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void eat_sleep(t_data *data)
{
	pthread_mutex_lock(data->philo[data->i]->forkl);
	pthread_mutex_lock(data->philo[data->i]->forkr);
	usleep(data->time_to_eat);
	pthread_mutex_lock(data->philo[data->i]->forkl);
	pthread_mutex_lock(data->philo[data->i]->forkr);
	gettimeofday(&(data->philo[data->i]->start_philo), NULL);
	usleep(data->time_to_sleep);
}

void init_forkl(t_data *data)
{
	if (data->i == 0)
		return;
	if (data->i == data->nbr_of_philo - 1)
	{
		data->philo[data->i]->forkl = data->philo[0]->forkr;
		return;
	}
	data->philo[data->i]->forkl = data->philo[data->i - 1]->forkr;
}

int philo_wait(t_data *data)
{
	if (&(data->start) + data->time_to_eat > data->time_to_die)
		return (-1);
	else
	{
		if (data->i % 3 != 1)
		{
			if (data->i % 3 == 0 &&
				&(data->start) + (data->time_to_eat * 2) < data->time_to_die)
				usleep(data->time_to_eat * 2);
			else if (data->i % 3 == 1 &&
					 &(data->start) + data->time_to_eat < data->time_to_die)
				usleep(data->time_to_eat);
			else
				return (data->i);
		}
	}
	return (0);
}

int life_philo(t_data *data)
{
	int nbr_meals;
	int philo_die;

	nbr_meals = 0;
	usleep(1);
	while (&(data->philo[data->i]->end_philo) < data->time_to_die)
	{
		philo_die = philo_wait(data);
		if (philo_die != 0)
		{
			if (philo_die > 0)
				printf();
			join_all & exit;
		}
		if (nbr_meals <= data->nbr_of_meals)
		{
			pthread_create(&data->philo[data->i], NULL, eat_sleep, data);
			nbr_meals++;
		}
		gettimeofday(&(data->philo[data->i]->end_philo), NULL);
	}
	return (-1);
}

void philo_init(t_data *data, t_philo **philo)
{
	int i;

	i = 0;
	philo = malloc(sizeof(t_philo) * (data->nbr_of_philo + 1));
	if (philo == NULL)
		return;
	while (i < data->nbr_of_philo)
	{
		data->i = i;
		if (pthread_mutex_init(data->philo[i]->forkr, NULL) != 0)
			// stop
			init_forkl(data);
		i++;
	}
	while (i >= 0)
	{
		data->philo[i]->philosopher = pthread_create(&philo[i], NULL, life_philo, data);
		i--;
	}
}
