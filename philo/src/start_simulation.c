/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:30:58 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/06 12:02:26 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_simulation_philo(t_philo **philo, t_checker checker,
			t_data_simulation *d_sim)
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
		data_clear(data_sim);
		return (-1);
	}
	checker.status_finish = LOOP;
	if (init_philo(philo, checker, data_sim) == -1)
		return (-1);
	start_simulation_philo(philo, checker, data_sim);
	return (0);
}
