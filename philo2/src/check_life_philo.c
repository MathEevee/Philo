/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_life_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:16:33 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/22 16:14:05 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	checker_meals(t_philo **philo, t_checker *checker)
{
	int	i;
	int	nbr_philo_full;

	i = 0;
	nbr_philo_full = 0;
	while (i < checker->nbr_of_philo)
	{
		if (philo[i]->status_meals == FULL_MEALS)
			nbr_philo_full++;
		if (nbr_philo_full == checker->nbr_of_philo)
			return (1);
		i++;
	}
	printf("nbr_philo_full : %d\n", nbr_philo_full);
	return (0);
}

void	check_time_actions(t_philo *philo)
{
	long long int	diff;
	long long int	time_to_eat;
	long long int	time_to_die;

	gettimeofday(&philo->end_philo, NULL);
	diff = calc_time_philo(philo);
	time_to_eat = philo->time_to_eat;
	time_to_die = philo->time_to_die;
	if (philo->status == EAT)
	{
		if (diff + time_to_eat > time_to_die)
			philo_die(philo, diff);
	}
	else if (philo->status == THINK)
	{
		if (diff + time_to_eat * 2 > time_to_die)
			philo_die(philo, diff);
	}
	else if (philo->status == SLEEP)
	{
		if (diff + time_to_eat * 3 > time_to_die)
			philo_die(philo, diff);
	}
}

void	check_life(t_philo **philo, t_checker *checker)
{
	pthread_mutex_t	*wait_print;
	int				i;

	i = 0;
	wait_print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(wait_print, NULL);
	while (/*nbr_of_philo_full <= checker->nbr_of_philo*/ 1)
	{
		pthread_mutex_lock(wait_print);
		if (checker_meals(philo, checker) == 1)
			break ;
		if (philo[i]->status != NOTHING && philo[i]->print == YES)
			print_action(checker, i, philo[i]);
		if (philo[i]->status == DEAD)
			break ;
		i++;
		pthread_mutex_unlock(wait_print);
		if (i == checker->nbr_of_philo)
			i = 0;
	}
	gettimeofday(&checker->end, NULL);
	end_message(philo, checker);
}