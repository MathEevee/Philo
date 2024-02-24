/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:45:27 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/22 16:13:30 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_checker *checker, int i, t_philo *philo)
{
	long long int	diff;

	gettimeofday(&checker->end, NULL);
	diff = calc_time(checker);
	printf("%llu : philo %d ", diff, i + 1);
	if (philo->status == TAKE_FORK)
		printf("taken forks\n");
	if (philo->status == EAT)
		printf("is eating\n");
	if (philo->status == SLEEP)
		printf("is sleeping\n");
	if (philo->status == THINK)
		printf("is thinking\n");
	if (philo->status == DEAD)
	{
		printf("died\n");
		checker->finish = END;
		return ;
	}
	philo->print = NO;
}

void	end_message(t_philo **philo, t_checker *checker)
{
	int	i;
	long long int diff;

	i = 0;
	diff = calc_time(checker);
	printf("%llu : ", diff);
	if (checker->status_finish == FULL_MEALS)
		printf("The simulation was successful\n");
	else
		printf("The simulation was failed\n");
	clear_stop(philo, checker, i);
}
