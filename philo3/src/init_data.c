/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:31:40 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/17 18:18:26 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(char **av, t_data *data)
{
	data->nbr_of_philo = ft_atoll(av[1]);
	printf("%d\n", data->nbr_of_philo);
	data->time_to_die = ft_atoll(av[2]);
	printf("%lld\n", data->time_to_die);
	data->time_to_eat = ft_atoll(av[3]);
	printf("%lld\n", data->time_to_eat);
	data->time_to_sleep = ft_atoll(av[4]);
	printf("%lld\n", data->time_to_sleep);
	data->nbr_of_meals = ft_atoll(av[5]);
	printf("%d\n", data->nbr_of_meals);
}

void init_forkl(t_data *data)
{
	pthread_mutex_t	forkl;

	if (data->i == 0)
		return ;
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

void	init_forkr(t_data *data)
{
	pthread_mutex_t	forkr;
	
	pthread_mutex_init(&forkr, NULL);
	data->philo[data->i]->forkr = forkr;
	init_forkl(data);
}

void	philo_init(t_data *data, t_philo **philo)
{
	int				i;

	philo = malloc(sizeof(t_philo) * (data->nbr_of_philo + 1));
	if (philo == NULL)
		return;
	i = 0;
	data->finish = LOOP;
	while (i <= data->nbr_of_philo - 1)
	{
		philo[i] = malloc(sizeof(t_philo));
		if (philo[i] == NULL)
			return;
		data->philo[i]->status = NOTHING;
		// printf("test\n");
		// printf("data->%d\n", data->philo[i]->status);
		data->i = i;
		//pthread_create(&data->philo[i]->philosopher, NULL, life_philo, data);
		i++;
	}
	while (i >= 0)
	{
		//pthread_join(data->philo[i]->philosopher, NULL);
		i--;
	}
	init_forkl(data);
}

void	init_data_death(t_data *data)
{
	data->philo[data->i]->status = DEAD;
	data->finish = END;
}
