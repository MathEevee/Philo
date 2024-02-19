/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier_a_suppr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:01:16 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/19 13:14:23 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_all(t_checker *checker, t_philo **philo)
{
	int	i;

	i = 0;
	printf("checkernbr_of_philo : %d\n", checker->nbr_of_philo);
	printf("checkertime_to_die : %lld\n", checker->time_to_die);
	printf("checkertime_to_eat : %lld\n", checker->time_to_eat);
	printf("checkertime_to_sleep : %lld\n", checker->time_to_sleep);
	printf("checkernbr_of_meals : %d\n", checker->nbr_of_meals);
	printf("checkerfinish : %d\n", checker->finish);
	while (i <= checker->nbr_of_philo - 1)
	{
		printf("checkerphilo[i].i : %d\n", philo[i]->i);
		printf("checkerphilo[i].status : %d\n", philo[i]->status);
		printf("checkerphilo[i].nbr_meals : %d\n", philo[i]->nbr_meals);
		printf("\n\n");
		i++;
	}
}