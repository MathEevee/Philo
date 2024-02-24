/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:45:27 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/24 10:02:36 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, int status)
{
	long long int	diff;

	diff = calc_time(philo->all_d_ph);
	printf("%llu : philo %d ", diff, philo->idx_philo + 1);
	if (status == TAKE_FORK)
		printf("is taken fork\n");
	if (status == EAT)
		printf("is eating\n");
	if (status == SLEEP)
		printf("is sleeping\n");
	if (status == THINK)
		printf("is thinking\n");
	if (status == DEAD)
	{
		printf("died\n");
		philo->loop = DEAD;
		return ;
	}
}


void	end_message(t_philo **philo, int i, t_checker checker)
{
	long long int diff;

	diff = calc_time(philo[i]->all_d_ph);
	printf("%llu : ", diff);
	clear_stop(philo, checker, i);
	if (philo[i]->status == DEAD)
		printf("The simulation was failed\n");
	else
		printf("The simulation was successful\n");
}
