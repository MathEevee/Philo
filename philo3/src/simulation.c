/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:10:36 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/24 13:31:22 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	first_part(t_philo *philo)
{
	philo_think(philo);
	if ((philo->idx_philo + 1) % 2 == 0)
		usleep(500);
}

static int	philo_routine(t_philo *philo)
{
	check_time_actions(philo);
	if (philo->status == DEAD)
		return (-1);
	philo_eat(philo);
	check_time_actions(philo);
	if (philo->status == DEAD)
		return (-1);
	philo_sleep(philo);
	check_time_actions(philo);
	if (philo->status == DEAD)
		return (-1);
	if (philo->status_meals == FULL_PHILO)
		return (-1);
	check_time_actions(philo);
	return (0);
}

static void	*life_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	philo->loop = LOOP;
	gettimeofday(&philo->ptime->start, NULL);
	check_time_actions(philo);
	philo_think(philo);
	first_part(philo);
	while (philo->status_meals == NOTHING)
	{
		if (philo_routine(philo) == -1)
			break ;
		philo_think(philo);
	}
	return (NULL);
}

void	start_simulation_philo(t_philo **philo, t_checker checker, t_data_simulation *d_sim)
{
	int	i;

	i = 0;
	gettimeofday(&d_sim->gtimer->start, NULL);
	while (i < checker.nbr_of_philo)
	{
		pthread_create(&philo[i]->philosopher, NULL, life_philo, philo[i]);
		i++;
	}
	check_life(philo, checker, d_sim);
}

int	begin_simulation(char *av, t_data_simulation *data_sim)
{
	t_checker	checker;
	t_philo		**philo;

	checker.nbr_of_philo = ft_atoll(av);
	philo = malloc(sizeof(t_philo) * (checker.nbr_of_philo + 1));
	if (philo == NULL)
	{
		// free_data_sim();
		return (-1);
	}
	checker.status_finish = LOOP;
	if (init_philo(philo, checker, data_sim) == -1)
	{
		// free_data_sim();
		return (-1);
	}
	start_simulation_philo(philo, checker, data_sim);
	return (0);
}
