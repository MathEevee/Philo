/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:59:28 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/17 18:15:50 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data		*data;
	t_philo		**philo;
	pthread_t	*timer;

	if (check_arg(ac, av) == -1 || check_data(av) == -1)
		return (0);
	philo = NULL;
	timer = NULL;
	//data = malloc(sizeof(t_data) + sizeof(t_philo) * (ft_atoll(av[1] + 1)));
	data = malloc(100000000);
	if (data == NULL)
		return (0);
	init_data(av, data);
	philo_init(data, philo);
	//pthread_create(timer, NULL, check_action, data);
	//pthread_join(*timer, NULL);
	return (0);
}