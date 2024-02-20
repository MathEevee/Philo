/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:40:26 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/20 13:19:12 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulation_life(t_philo **philo, t_checker *checker)
{
	int	i;

	i = 0;
	gettimeofday(&checker->start, NULL);
	while (i <= checker->nbr_of_philo - 1)
	{
		pthread_create(&philo[i]->philosopher, NULL, life_philo, philo[i]);
		i++;
	}
	check_life(philo, checker);
}
