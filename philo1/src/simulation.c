/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:10:36 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/21 09:57:24 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	first_part(t_philo *philo)
{
	check_time_actions(philo);
	if ((philo->idx_philo + 1) % 3 == 1)
	{
		philo_think(philo);
		philo_eat(philo);
	}
	else if ((philo->idx_philo + 1) % 3 == 2)
	{
		usleep(philo->time_to_eat);
		philo_think(philo);
	}
	else
	{
		usleep(philo->time_to_eat * 2);
		philo_think(philo);
	}
}

static void	*life_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	philo->loop = LOOP;
	gettimeofday(&philo->start_philo, NULL);
	first_part(philo);
	while (philo->loop == LOOP)
	{
		check_time_actions(philo);
		if (philo->status == DEAD)
			break ;
		philo_eat(philo);
		check_time_actions(philo);
		if (philo->status == DEAD)
			break ;
		philo_sleep(philo);
		check_time_actions(philo);
		if (philo->status == DEAD)
			break ;
		philo_think(philo);
	}
	return (NULL);
}

void	start_simulation(t_philo **philo, t_checker *checker)
{
	int	i;

	i = 0;
	gettimeofday(&checker->start, NULL);
	while (i < checker->nbr_of_philo)
	{
		pthread_create(&philo[i]->philosopher, NULL, life_philo, philo[i]);
		i++;
	}
	check_life(philo, checker);
}
