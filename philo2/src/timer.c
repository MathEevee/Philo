/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:06:48 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/16 14:58:44 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timer_to_life(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (data->philo[data->i]->status == DEAD)
		{
			philo_die(data);
			break ;
		}
		else if (data->philo[data->i]->status == FULL)
		{
			philo_full(data);
			break ;
		}
		else if (data->philo[data->i]->status != 0)
			print_action(data);
		i++;
		if (i == data->nbr_of_philo)
			i = 0;
	}
}
