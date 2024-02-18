/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier_a_suppr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:01:16 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/18 17:06:50 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_all(t_data *data)
{
	int	i;

	i = 0;
	printf("data->nbr_of_philo : %d\n", data->nbr_of_philo);
	printf("data->time_to_die : %lld\n", data->time_to_die);
	printf("data->time_to_eat : %lld\n", data->time_to_eat);
	printf("data->time_to_sleep : %lld\n", data->time_to_sleep);
	printf("data->nbr_of_meals : %d\n", data->nbr_of_meals);
	printf("data->finish : %d\n", data->finish);
	while (i <= data->nbr_of_philo - 1)
	{
		printf("data->philo[i].i : %d\n", data->philo[i].i);
		printf("data->philo[i].status : %d\n", data->philo[i].status);
		printf("data->philo[i].nbr_meals : %d\n", data->philo[i].nbr_meals);
		printf("\n\n");
		i++;
	}
}