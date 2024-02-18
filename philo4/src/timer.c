/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:58:06 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/18 10:48:09 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_data *data, int i)
{
	unsigned long long int	diff;

	gettimeofday(&data->end, NULL);
	diff = calc_time(data);
	printf("%llu : philo %d ", diff, i);
	if (data->philo[i]->status == TAKE_FORK_R)
		printf("take a fork\n");
	if (data->philo[i]->status == EAT)
		printf("is eating\n");
	if (data->philo[i]->status == SLEEP)
		printf("is sleeping\n");
	if (data->philo[i]->status == THINK)
		printf("is sleeping\n");
	if (data->philo[i]->status == DEAD)
	{
		printf("died\n");
		data->finish = END;
		return ;
	}
	data->philo[i]->status = 0;
}

void	send_end_msg(t_data *data, int i)
{
	if (data->philo[i]->status == FULL)
		printf("Everyone ate\n");
	else
		printf("Simulation has failed\n");
	return ;
}

void	check_time_actions(t_data *data)
{
	long long int	diff;

	gettimeofday(&data->philo[data->i]->end_philo, NULL);
	diff = calc_time_philo(data);
	if (data->philo[data->i]->status == EAT)
	{
		if (diff + data->time_to_eat > data->time_to_die)
			init_data_death(data);
	}
	else if (data->philo[data->i]->status == SLEEP)
	{
		if (diff + data->time_to_eat * 3 > data->time_to_die)
			init_data_death(data);
	}
	else if (data->philo[data->i]->status == THINK)
	{
		if (diff + data->time_to_eat * 2 > data->time_to_die)
			init_data_death(data);
	}
}

void	*check_action(void *arg)
{
	int				nbr_full_philo;
	int				i;
	pthread_mutex_t	*wait_write;
	t_data 			*data;

	data = (t_data *) arg;
	wait_write = NULL;
	pthread_mutex_init(wait_write, NULL);
	nbr_full_philo = 0;
	i = 0;
	while (nbr_full_philo <= data->nbr_of_philo)
	{
		if (data->philo[data->i]->status == FULL)
			nbr_full_philo++;
		if (data->finish == END)
			break ;
		if (data->philo[data->i]->status != 0)
		{
			pthread_mutex_lock(wait_write);
			print_action(data, i);
			pthread_mutex_unlock(wait_write);
		}
		i++;
		if (i == data->nbr_of_philo)
			i = 0;
	}
	send_end_msg(data, i);
	return (NULL);
}
