/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:34:13 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/16 16:03:20 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


int life_philo(t_data *data)
{
	data->finish = LOOP;
	first_part(data);
	while (data->finish == 1)
		life_loop(data);
}

void init_forkl(t_data *data)
{
	pthread_mutex_t	*forkl;

	if (data->i == 0)
		return;
	pthread_mutex_init(&forkl, NULL);
	if (data->i == data->nbr_of_philo - 1)
	{
		forkl = (data->philo[0]->forkr);
		data->philo[data->i]->forkl = &forkl;
		return ;
	}
	forkl = (data->philo[data->i - 1]->forkr);
	data->philo[data->i]->forkl = &forkl;
}

void philo_init(t_data *data, t_philo **philo)
{
	int				i;
	pthread_mutex_t	forkr;

	i = 0;
	philo = malloc(sizeof(t_philo) * (data->nbr_of_philo + 1));
	if (philo == NULL)
		return;
	while (i < data->nbr_of_philo)
	{
		pthread_mutex_init(&forkr, NULL);
		data->philo[i]->forkr = &forkr;
		data->i = i;
		init_forkl(data);
		i++;
	}
	while (i >= 0)
	{
		data->philo[i]->philosopher = pthread_create(&philo[i], NULL, life_philo, data);
		i--;
	}
}
