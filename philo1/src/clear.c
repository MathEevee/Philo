/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:48:10 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/21 09:37:16 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void clear_stop(t_philo **philo, t_checker *checker, int i)
{
	int	j;

	j = 0;
	while (philo[j] != NULL)
	{
		pthread_mutex_destroy(philo[j]->forkr);
		pthread_mutex_destroy(philo[j]->forkl);
		if (j == i)
			j++;
		if (j == checker->nbr_of_philo)
			break ;
		pthread_join(philo[j]->philosopher, NULL);
	}
	free_philo(philo);
	free(checker);
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
