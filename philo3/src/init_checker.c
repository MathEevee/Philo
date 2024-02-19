/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:31:40 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/19 16:23:16 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_checker(char **av, t_checker *checker)
{
	checker->nbr_of_philo = ft_atoll(av[1]);
	checker->time_to_die = ft_atoll(av[2]);
	checker->time_to_eat = ft_atoll(av[3]);
	checker->time_to_sleep = ft_atoll(av[4]);
	checker->nbr_of_meals = ft_atoll(av[5]);
}

/*void	init_data_death(t_checker *checker)
{
	checkerphilo[checker->i].status = DEAD;
	checker->finish = END;
}*/
