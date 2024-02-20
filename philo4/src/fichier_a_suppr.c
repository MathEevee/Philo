/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier_a_suppr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:29:52 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/20 15:45:05 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_all(t_checker *checker, t_philo **philo)
{
	int	i;

	i = 0;
	printf("nbr_of_philo : %d\n", checker->nbr_of_philo);
	while (i <= checker->nbr_of_philo - 1)
	{
		printf("philo[i]->i : %d\n", philo[i]->idx_philo);
		printf("philo[i]->status : %d\n", philo[i]->status);
		printf("philo[i]->nbr_of_meals_total : %d\n", philo[i]->nbr_of_meals_total);
		printf("philo[i]->time_to_eat : %lld\n", philo[i]->time_to_eat);
		printf("philo[i]->time_to_sleep : %lld\n", philo[i]->time_to_sleep);
		printf("philo[i]->nbr_meals_count : %d\n", philo[i]->nbr_meals_count);
		printf("philo[i]->time_to_die : %lld\n", philo[i]->time_to_die);
		printf("\n\n");
		i++;
	}
}
