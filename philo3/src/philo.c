/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:59:28 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/19 16:36:10 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_checker	*checker;
	pthread_t	timer;
	t_philo		**philo;

	if (check_arg(ac, av) == -1)
		return (0);
	checker = malloc(sizeof(t_checker));
	init_data(av, checker);
	philo = philo_init(checker);
	simulation_life(philo, checker);
	return (0);
}