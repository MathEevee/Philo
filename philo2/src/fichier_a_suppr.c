/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier_a_suppr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:29:52 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/23 11:01:16 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_all(t_checker checker, t_philo **philo)
{
	int	i;

	i = 0;
	printf("nbr_of_philo : %lld\n", checker.nbr_of_philo);
	while (i < checker.nbr_of_philo)
	{
		printf("philo[i]->i : %d\n", philo[i]->idx_philo);
		printf("philo[i]->status : %d\n", philo[i]->status);
		printf("philo[i]->nbr_of_meals_total : %d\n", philo[i]->nbr_meals_count);
		printf("\n\n");
		i++;
	}
}
