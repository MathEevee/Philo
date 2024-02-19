/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:31:40 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/19 09:16:52 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(char **av, t_data *data)
{
	data->nbr_of_philo = ft_atoll(av[1]);
	data->time_to_die = ft_atoll(av[2]);
	data->time_to_eat = ft_atoll(av[3]);
	data->time_to_sleep = ft_atoll(av[4]);
	data->nbr_of_meals = ft_atoll(av[5]);
}

void init_forkl(int i, t_philo **philo, t_data *data)
{
	pthread_mutex_t	forkl;
	
	if (i == 0)
		return ;
	pthread_mutex_init(&forkl, NULL);
	if (i == data->nbr_of_philo - 1)
	{
		philo[i]->forkl = philo[0]->forkr;
		return ;
	}
	forkl = philo[i - 1]->forkr;
	philo[i]->forkl = forkl;
}

void	init_forkr(int i, t_philo **philo, t_data *data)
{
	pthread_mutex_t	forkr;
	
	pthread_mutex_init(&forkr, NULL);
	philo[i]->forkr = forkr;
	init_forkl(i, philo, data);
}

void	philo_init(t_data *data)
{
	int				i;
	t_philo			**philo;

	i = 0;
	data->finish = LOOP;
	philo = malloc(sizeof(t_philo) * (data->nbr_of_philo));
	while (i <= data->nbr_of_philo - 1)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->nbr_meals = 0;
		philo[i]->status = NOTHING;
		philo[i]->i = i;
		init_forkr(i, philo, data);
		i++;
	}
	data->philo = *(philo);
	gettimeofday(&data->start, NULL);
	while (i >= 0)
	{
		data->i = i;
		pthread_create(&data->philo[i].philosopher, NULL, life_philo, data);
		i--;
	}
}

void	init_data_death(t_data *data)
{
	data->philo[data->i].status = DEAD;
	data->finish = END;
}
