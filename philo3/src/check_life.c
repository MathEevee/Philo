/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:04:31 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/20 13:30:17 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_life(t_philo **philo, t_checker *checker)
{
	pthread_mutex_t	wait_print;
	int	i;
	int	nbr_of_philo_full;

	i = 0;
	nbr_of_philo_full = 0;
	pthread_mutex_init(&wait_print, NULL);
	while (nbr_of_philo_full <= checker->nbr_of_philo)
	{
		pthread_mutex_lock(&wait_print);
		if (philo[i]->status == FULL)
			nbr_of_philo_full++;
		if (philo[i]->status == DEAD)
			break ;
		if (philo[i]->status != NOTHING)
			printf_conditions();
		pthread_mutex_unlock(&wait_print);
		i++;
		if (i == checker->nbr_of_philo)
			i = 0;
	}
	gettimeofday(&checker->end, NULL);
	end_message(philo, checker, nbr_of_philo_full);
}
