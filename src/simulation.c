/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:34:13 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/12 22:29:01 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_init(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * (data->nbr_of_philo + 1));
	if (philo == NULL)
		return ;
	while (i < data->nbr_of_philo)
	{
		philo[i]->forkr = pthread_mutex_init()
		i++;
	}
}
