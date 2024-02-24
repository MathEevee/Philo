/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:48:10 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/24 13:11:18 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_end(t_philo **philo, t_checker checker)
{
	int	i;

	i = 0;
	while (i < checker.nbr_of_philo)
	{
		philo[i]->status = END;
		i++;
	}
}

void clear_stop(t_philo **philo, t_checker checker, int i)
{
	int	j;

	j = 0;
	(void) i;
	pthread_mutex_destroy(philo[i]->write);
	while (philo[j] != NULL)
	{
		pthread_join(philo[j]->philosopher, NULL);
		pthread_mutex_destroy(philo[j]->forkr);
		pthread_mutex_destroy(philo[j]->forkl);
		if (j == i)
			j++;
		if (j == checker.nbr_of_philo)
			break ;
	}
	free_philo(philo);
}

void	free_philo(t_philo **philo)
{
	int	i;

	i = 0;
	while (philo[i] != NULL)
	{
		free(philo[i]);
		i++;
	}
	free(philo);
}
