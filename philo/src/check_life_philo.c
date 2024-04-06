/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_life_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:16:33 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/06 11:20:33 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_full(t_philo **philo, t_checker checker)
{
	int	i;
	int	nbr_philo_full;

	nbr_philo_full = 0;
	i = 0;
	while (i < checker.nbr_of_philo)
	{
		if (philo[i]->status_meals == FULL_PHILO)
			nbr_philo_full++;
		if (nbr_philo_full >= checker.nbr_of_philo)
			return (1);
		i++;
	}
	return (0);
}

void	check_time_actions(t_philo *philo)
{
	long long int	diff;
	long long int	time_to_sleep;
	long long int	time_to_die;
	long long int	time_to_eat;
	int				philo_status;

	gettimeofday(&philo->ptime->end, NULL);
	diff = calc_time_philo(philo);
	time_to_sleep = philo->all_d_ph->time_to_sleep;
	time_to_die = philo->all_d_ph->time_to_die;
	time_to_eat = philo->all_d_ph->time_to_eat;
	pthread_mutex_lock(philo->write);
	philo_status = philo->status;
	pthread_mutex_unlock(philo->write);
	if (philo_status == THINK && diff > time_to_die)
		philo_die(philo, diff);
	if (philo_status == TAKE_FORK && diff > time_to_die)
		philo_die(philo, diff);
	if (philo_status == SLEEP && diff > time_to_die)
		philo_die(philo, diff);
}

static void	check_status(t_checker *checker, t_philo **philo, int status, int i)
{
	checker->status_finish = status;
	pthread_mutex_unlock(philo[i]->write);
	set_end(philo, *checker);
}

void	check_life(t_philo **philo, t_checker checker, t_data_simulation *d_sim)
{
	int	i;

	i = 0;
	checker.status_finish = LOOP;
	while (checker.status_finish == LOOP)
	{
		pthread_mutex_lock(philo[i]->write);
		if (check_full(philo, checker) == 1)
		{
			check_status(&checker, philo, FULL_PHILO, i);
			break ;
		}
		if (philo[i]->status == DEAD)
		{
			check_status(&checker, philo, DEAD, i);
			break ;
		}
		pthread_mutex_unlock(philo[i]->write);
		i++;
		if (i >= checker.nbr_of_philo)
			i = 0;
		usleep(100);
	}
	gettimeofday(&d_sim->gtimer->end, NULL);
	end_message(philo, checker, d_sim);
}
