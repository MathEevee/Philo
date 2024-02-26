/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:10:02 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/25 15:27:19 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void init_forkl(t_philo **philo, int nbr_philo)
{
	int	i;

	i = 0;
	while (i < nbr_philo)
	{
		if (i == 0)
			philo[i]->forkl = philo[nbr_philo - 1]->forkr;
		else
			philo[i]->forkl = philo[i - 1]->forkr;
		i++;
	}
}


static int	value_philo(t_philo *philo, int i, pthread_mutex_t *m_phi, t_data_simulation *d_sim)
{
	t_times_philo *timer;
	pthread_mutex_t	*forkr;

	timer = malloc(sizeof(t_times_philo));
	if (timer == NULL)
		return (-1);
	forkr = malloc(sizeof(pthread_mutex_t));
	if (forkr == NULL)
		return (-1);
	philo->ptime = timer;
	philo->all_d_ph = d_sim;
	philo->nbr_meals_count = 0;
	philo->status_meals = NOTHING;
	philo->write = m_phi;
	philo->status = NOTHING;
	philo->idx_philo = i;
	philo->loop = LOOP;
	philo->forkr = forkr;
	pthread_mutex_init(philo->forkr, NULL);
	return (0);
}	

static int	philo_data(t_philo **philo, int nbr_philo, pthread_mutex_t	*m_phi, t_data_simulation *d_sim)
{
	int i;

	i = 0;
	while (i < nbr_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		if (philo[i] == NULL)
		{
			// free_philo(philo);
			return (-1);
		}
		if (value_philo(philo[i], i, m_phi, d_sim) == -1)
		{
			// free_philo(philo);
			return (-1);
		}
		i++;
	}
	pthread_mutex_init(m_phi, NULL);
	init_forkl(philo, nbr_philo);
	return (0);
}

int	init_philo(t_philo **philo, t_checker checker, t_data_simulation *d_sim)
{
	pthread_mutex_t	*philo_print;

	philo_print = malloc(sizeof(pthread_mutex_t));
	if (philo_print == NULL)
	{
		free(philo);
		return (-1);
	}
	if (philo_data(philo, checker.nbr_of_philo, philo_print, d_sim) == -1)
		// clear_all()
	pthread_mutex_init(philo_print, NULL);
	return (0);
}
