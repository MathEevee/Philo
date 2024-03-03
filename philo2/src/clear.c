/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:48:10 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/27 10:57:59 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_end(t_philo **philo, t_checker checker)
{
	int	i;

	i = 0;
	while (i < checker.nbr_of_philo)
	{
		if (philo[i]->status != DEAD)
			philo[i]->status = END;
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
	while (philo[i] != NULL)
	{
		pthread_mutex_unlock(philo[i]->forkl);
		pthread_mutex_unlock(&philo[i]->forkr);
		free(philo[i]);
		pthread_mutex_destroy(&philo[i]->forkr);
		pthread_detach(philo[i]->philosopher);
		i++;
	}
	free(philo);
}
