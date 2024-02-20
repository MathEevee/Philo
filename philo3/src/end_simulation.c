/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:45:59 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/20 14:45:44 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_stop(t_philo **philo, t_checker *checker, int i)
{
	int	j;

	j = 0;
	while (j <= checker->nbr_of_philo - 1)
	{
		if (j == i)
			j++;
		if (j > i)
			break ;
		pthread_join(&philo[j]->philosopher, NULL);
		j++;
	}
	clear_tab();
	exit(0);
}
