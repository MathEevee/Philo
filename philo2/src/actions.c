/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:08:23 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/19 14:36:05 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo[philo->index_of_philo].forkl);
	philo[philo->index_of_philo]->status = EAT;
	philo[philo->index_of_philo]->nbr_meals++;
	usleep(checkertime_to_eat);
	gettimeofday(&checkerphilo[checkeri].start_philo, NULL);
}

void	philo_sleep(t_data *checker)
{
	pthread_mutex_unlock(&checkerphilo[checkeri].forkr);
	pthread_mutex_unlock(&checkerphilo[checkeri].forkl);
	checkerphilo[checkeri].status = SLEEP;
	usleep(checkertime_to_sleep);
}

void	philo_think(t_data *checker)
{
	checkerphilo[checkeri].status = THINK;
	pthread_mutex_lock(&checkerphilo[checkeri].forkr);
	checkerphilo[checkeri].status = TAKE_FORK_R;
}

void	first_part(t_data *checker)
{
	checkerphilo[checkeri].status = THINK;
	check_time_actions(data);
	if (checkeri % 3 == 1)
	{
		philo_think(data);
		philo_eat(data);
	}
	else if (checkeri % 3 == 2)
		philo_think(data);
	else
	{
		usleep(checkertime_to_eat);
		philo_think(data);
	}
}

void	*life_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	gettimeofday(&philo[philo->index_of_philo].start_philo, NULL);
	first_part(philo);
	while (philo[philo->index_of_philo].nbr_meals != philo[philo->index_of_philo].nbr_meals_full)
	{
		check_time_actions(philo);
		philo_eat(philo);
		check_time_actions(philo);
		philo_sleep(philo);
		check_time_actions(philo);
		philo_think(philo);
	}
	return (NULL);
}
