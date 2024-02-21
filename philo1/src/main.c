/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:05:31 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/20 17:35:03 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_checker	*checker;
	t_philo		**philo;

	if (check_arg(ac, av) == -1)
		return (0);
	checker = malloc(sizeof(t_checker));
	//protec
	checker->nbr_of_philo = ft_atoll(av[1]);
	philo = philo_init(checker, av);
	// print_all(checker, philo);
	//protec
	start_simulation(philo, checker);
	return (0);
}
