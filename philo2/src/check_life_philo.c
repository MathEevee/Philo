/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_life_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:16:33 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/27 11:40:53 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_full(t_philo **philo, t_checker checker)
{
	int i;
	int nbr_philo_full;
	// long long int	diff;
	
	nbr_philo_full = 0;
	i = 0;
	while (i < checker.nbr_of_philo)
	{
		pthread_mutex_lock(philo[i]->write);
		// diff = calc_time(philo[i]->all_d_ph);
		if (philo[i]->status_meals == FULL_PHILO)
			nbr_philo_full++;
		if (nbr_philo_full >= checker.nbr_of_philo)
		{
			pthread_mutex_unlock(philo[i]->write);
			return (1);
		}
		pthread_mutex_unlock(philo[i]->write);
		i++;
	}
	return (0);
}

void	check_time_actions(t_philo *philo)
{
	long long int	diff;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	time_to_die;

	gettimeofday(&philo->ptime->end, NULL);
	diff = calc_time_philo(philo);
	time_to_eat = philo->all_d_ph->time_to_eat;
	time_to_sleep = philo->all_d_ph->time_to_sleep;
	time_to_die = philo->all_d_ph->time_to_die;
	if (diff + time_to_sleep >= time_to_die)
		philo_die(philo, diff);
	if (diff + time_to_eat >= time_to_die)
		philo_die(philo, diff);
}

void	check_life(t_philo **philo, t_checker checker, t_data_simulation *d_sim)
{
	int	i;

	i = 0;
    checker.status_finish = LOOP;
	while (checker.status_finish == LOOP)
	{
        if (check_full(philo, checker) == 1)
        {
            checker.status_finish = FULL_PHILO;
            break ;
        }
        if (philo[i]->status == DEAD)
		{
			checker.status_finish = DEAD;
			set_end(philo, checker);
			break ;
		}
        i++;
        if (i >= checker.nbr_of_philo)
            i = 0;
	}
	gettimeofday(&d_sim->gtimer->end, NULL);
	end_message(philo, checker);
}
