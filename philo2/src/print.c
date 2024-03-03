/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:45:27 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/27 11:40:34 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdbool.h>

void	print_action(t_philo *philo, int status)
{
	long long int	diff;
	static bool		dead_print = false;

	pthread_mutex_lock(philo->write);
	diff = calc_time(philo->all_d_ph);
	printf("%llu : philo %d ", diff, philo->idx_philo + 1);
	if (status == TAKE_FORK && philo->status != END)
		printf("is taken fork\n");
	if (status == EAT && philo->status != END)
		printf("is eating\n");
	if (status == SLEEP && philo->status != END)
		printf("is sleeping\n");
	if (status == THINK && philo->status != END)
		printf("is thinking\n");
	if (status == DEAD && philo->status != END && dead_print == false)
	{
		dead_print = true;
		printf("died\n");
		philo->loop = DEAD;
	}
	pthread_mutex_unlock(philo->write);
}


void	end_message(t_philo **philo, t_checker checker)
{
	(void) philo;
	// clear_stop(philo, checker);
	if (checker.status_finish == DEAD)
		printf("The simulation was failed\n");
	else
		printf("The simulation was successful\n");
}
