/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:59:28 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/18 17:17:36 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data		*data;
	pthread_t	timer;

	if (check_arg(ac, av) == -1 || check_data(av) == -1)
		return (0);
	data = malloc(sizeof(t_data));
	init_data(av, data);
	philo_init(data);
	pthread_create(&timer, NULL, check_action, data);
	pthread_join(timer, NULL);
	return (0);
}