/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:48:10 by matde-ol          #+#    #+#             */
/*   Updated: 2024/03/24 12:29:59 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_end(t_philo **philo, t_checker checker)
{
	int	i;

	i = 0;
	while (i < checker.nbr_of_philo)
	{
		pthread_mutex_lock(philo[i]->write);
		if (philo[i]->status != DEAD)
			philo[i]->status = END;
		pthread_mutex_unlock(philo[i]->write);
		i++;
	}
}

void clear_stop(t_philo **philo, t_checker checker)
{
	int	j;

	j = 0;
	while (philo[j] != NULL)
	{
		pthread_join(philo[j]->philosopher, NULL);
		if (j == checker.nbr_of_philo)
			break ;
		j++;
	}
	free_philo(philo);
}

void	free_philo(t_philo **philo)
{
	int	i;

	i = 0;
	free(philo[0]->write);
	while (philo[i] != NULL)
	{
		// pthread_mutex_unlock(&philo[i]->forkr);
		// pthread_mutex_unlock(philo[i]->forkl);
		pthread_mutex_destroy(&philo[i]->forkr);
		free(philo[i]->ptime);
		free(philo[i]);
		// pthread_detach(philo[i]->philosopher);
		i++;
	}
	free(philo);
}
