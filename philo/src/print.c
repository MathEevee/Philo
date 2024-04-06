/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:45:27 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/06 11:41:18 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, int status)
{
	long long int	diff;
	static bool		died = false;

	pthread_mutex_lock(philo->write);
	diff = calc_time(philo->all_d_ph);
	if (philo->status == END || philo->status == DEAD || died)
	{
		pthread_mutex_unlock(philo->write);
		return ;
	}
	if (status == TAKE_FORK)
		printf("%llu : philo %d has taken a fork\n", diff, philo->idx + 1);
	if (status == EAT)
		printf("%llu : philo %d is eating\n", diff, philo->idx + 1);
	if (status == SLEEP)
		printf("%llu : philo %d is sleeping\n", diff, philo->idx + 1);
	if (status == THINK)
		printf("%llu : philo %d is thinking\n", diff, philo->idx + 1);
	if (status == DEAD)
	{
		printf("%llu : philo %d died\n", diff, philo->idx + 1);
		died = true;
		philo->loop = DEAD;
	}
	pthread_mutex_unlock(philo->write);
}

void	end_message(t_philo **philo, t_checker checker,
		t_data_simulation *d_sim)
{
	(void) philo;
	pthread_mutex_lock(philo[0]->write);
	if (checker.status_finish == DEAD)
		printf("The simulation was failed\n");
	else
		printf("The simulation was successful\n");
	pthread_mutex_unlock(philo[0]->write);
	clear_stop(philo, checker);
	data_clear(d_sim);
}
