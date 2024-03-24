/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_life_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:16:33 by matde-ol          #+#    #+#             */
/*   Updated: 2024/03/24 15:24:01 by matde-ol         ###   ########.fr       */
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
	// printf("philo %d diff = %llu\n", philo->idx_philo + 1, diff);
	// printf("philo %d time_to_eat = %llu\n", philo->idx_philo + 1, time_to_eat);
	// printf("philo %d time_to_sleep = %llu\n", philo->idx_philo + 1, time_to_sleep);
	// printf("philo %d time_to_die = %llu\n", philo->idx_philo + 1, time_to_die);
	pthread_mutex_lock(philo->write);
	int	philo_status = philo->status;
	pthread_mutex_unlock(philo->write);
	
	if (philo_status == EAT && time_to_sleep + diff > time_to_die)
		philo_die(philo, diff);
	if (philo_status == TAKE_FORK && diff > time_to_die)
	{
		// printf("philo %d detected died\n", philo->idx_philo + 1);
		philo_die(philo, diff);
	}
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
			set_end(philo, checker);
            break ;
        }
		pthread_mutex_lock(philo[i]->write);
        if (philo[i]->status == DEAD)
		{
			checker.status_finish = DEAD;
			pthread_mutex_unlock(philo[i]->write);
			set_end(philo, checker);
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