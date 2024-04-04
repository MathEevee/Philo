/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:45:27 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/04 13:40:07 by matde-ol         ###   ########.fr       */
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
		printf("%llu : philo %d is taken fork\n", diff, philo->idx_philo + 1);
	if (status == EAT)
		printf("%llu : philo %d is eating\n", diff, philo->idx_philo + 1);
	if (status == SLEEP)
		printf("%llu : philo %d is sleeping\n", diff, philo->idx_philo + 1);
	if (status == THINK)
		printf("%llu : philo %d is thinking\n", diff, philo->idx_philo + 1);
	if (status == DEAD)
	{
		printf("%llu : philo %d died\n", diff, philo->idx_philo + 1);
		died = true;
		philo->loop = DEAD;
	}
	pthread_mutex_unlock(philo->write);
}

static void	print_action(t_philo **philo, t_checker checker,
		t_data_simulation *d_sim)
{
	int				i;
	long long int	diff;

	i = 0;
	while (i < checker.nbr_of_philo)
	{
		if (philo[i]->status == DEAD)
		{
			diff = philo[i]->;
			printf("%llu : philo %d died\n", diff, i + 1);
			break ;
		}
		i++;
	}
}

void	end_message(t_philo **philo, t_checker checker,
		t_data_simulation *d_sim)
{
	(void) philo;
	pthread_mutex_lock(philo[0]->write);
	// print die 
	if (checker.status_finish == DEAD)
		printf("The simulation was failed\n");
	else
		printf("The simulation was successful\n");
	pthread_mutex_unlock(philo[0]->write);
	clear_stop(philo, checker);
	data_clear(d_sim);
}
