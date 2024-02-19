/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:45:59 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/19 16:46:27 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	clear_stop(t_philo **philo, t_checker *checker, int i)
{
	int	j;

	j = 0;
	while (j <= checker->nbr_of_philo - 1)
	{
		if (j == i)
			j++;
		if (j > i)
			break ;
		pthread_join(&philo[j]->philosopher, NULL);
		j++;
	}
	clear_tab();
	exit(0);
}

void	end_message(t_philo **philo, t_checker *checker, int nbr_of_philo_full)
{
	int	i;
	long long int diff;

	i = 0;
	diff = calc_time(checker);
	printf("%llu : ", diff);
	if (nbr_of_philo_full == checker->nbr_of_philo)
		printf("The simulation was successful\n");
	else
	{
		while (i <= checker->nbr_of_philo - 1)
		{
			if (philo[i]->status == DEAD)
				break ;
			i++;
		}
		printf("philo %d died\n");
	}
	clear_stop(philo, checker, i);
}
