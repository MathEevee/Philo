/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:54:50 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/16 15:54:08 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_condition(t_data *data)
{
	if (data->philo[data->i] <= 2)
		conditions_others(data);
	else if (data->philo[data->i] <= 5)
		conditions_primary_actions(data);
}

void	conditions_primary_actions(t_data *data)
{
	pthread_mutex_t write;
	
	pthread_mutex_init(&write, NULL);
	gettimeofday(&data->end, NULL);
	pthread_mutex_lock(&write);
	printf("%ld : philo %d ",
	((data->end.tv_sec * MS_TO_SEC + data->end.tv_usec ) -
	(data->start.tv_sec * MS_TO_SEC + data->start.tv_usec )) / 1000, data->i);
	if (data->philo[data->i]->status == EAT)
		printf("is eating\n");
	else if (data->philo[data->i]->status == SLEEP)
		printf("is sleeping\n");
	else if (data->philo[data->i]->status == THINK)
		printf("is thinking\n");
	data->philo[data->i]->status = 0;
	pthread_mutex_unlock(&write);
	pthread_mutex_destroy(&write);
}

void	conditions_end(t_data *data)
{
	pthread_mutex_t write;
	
	pthread_mutex_init(&write, NULL);
	gettimeofday(&data->end, NULL);
	pthread_mutex_lock(&write);
	printf("%ld : philo %d ",
	((data->end.tv_sec * MS_TO_SEC + data->end.tv_usec ) -
	(data->start.tv_sec * MS_TO_SEC + data->start.tv_usec )) / 1000, data->i);
	if (data->philo[data->i]->status == DEAD)
		printf("died");
	else if (data->philo[data->i]->status == FULL)
		printf("is full");
	pthread_mutex_unlock(&write);
	pthread_mutex_destroy(&write);
}

void	conditions_others(t_data *data)
{
	pthread_mutex_t write;
	
	pthread_mutex_init(&write, NULL);
	gettimeofday(&data->end, NULL);
	pthread_mutex_lock(&write);
	printf("%ld : philo %d ",
	((data->end.tv_sec * MS_TO_SEC + data->end.tv_usec ) -
	(data->start.tv_sec * MS_TO_SEC + data->start.tv_usec )) / 1000, data->i);
	if (data->philo[data->i]->status == TAKE_FORK_L)
		printf("has taken left fork");
	else if (data->philo[data->i]->status == TAKE_FORK_R)
		printf("has taken right fork");
	data->philo[data->i]->status = 0;
	pthread_mutex_unlock(&write);
	pthread_mutex_destroy(&write);
}
