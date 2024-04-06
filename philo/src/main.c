/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:05:31 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/06 11:39:58 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_checker(char **av, t_data_simulation *data_simulation)
{
	t_times_philo	*time;

	time = malloc(sizeof(t_times_philo));
	if (time == NULL)
	{
		free(data_simulation);
		return (-1);
	}
	data_simulation->gtimer = time;
	data_simulation->time_to_die = ft_atoll(av[2]);
	data_simulation->time_to_eat = ft_atoll(av[3]);
	data_simulation->time_to_sleep = ft_atoll(av[4]);
	if (av[5])
		data_simulation->nbr_of_meals = ft_atoll(av[5]);
	else
		data_simulation->nbr_of_meals = -1;
	return (0);
}

int	main(int ac, char **av)
{
	t_data_simulation	*data_simulation;

	if (check_arg(ac, av) == -1)
		return (0);
	data_simulation = malloc(sizeof(t_data_simulation));
	if (data_simulation == NULL)
		return (-1);
	if (init_checker(av, data_simulation) == -1)
		return (0);
	if (begin_simulation(av[1], data_simulation) == -1)
		return (0);
	return (0);
}
