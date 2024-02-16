/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:52:40 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/12 16:04:59 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data		*data;
	t_philo		**philo;

	if (check_arg(ac, av) == -1 || check_data(av) == -1)
		return (0);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	init_data(av, data);
	philo_init(data, philo);
	return (0);
}
	// printf("data->nbr_of_philo : %d\n", data->nbr_of_philo);
	// printf("data->time_to_die : %d\n", data->time_to_die);
	// printf("data->time_to_eat : %d\n", data->time_to_eat);
	// printf("data->time_to_sleep : %d\n", data->time_to_sleep);
	// printf("data->nbr_of_meals : %d\n", data->nbr_of_meals);