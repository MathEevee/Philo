/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:45:27 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/21 09:53:21 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_checker *checker, int i, t_philo *philo)
{
	long long int	diff;

	gettimeofday(&checker->end, NULL);
	diff = calc_time(checker);
	printf("%llu : philo %d ", diff, i + 1);
	if (philo->status == TAKE_FORK_R)
		printf("taken a fork\n");
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

void	end_message(t_philo **philo, t_checker *checker, int nbr_of_philo_full)
{
	int	i;
	long long int diff;

	i = 0;
	diff = calc_time(checker);
	printf("%llu : ", diff);
	if (nbr_of_philo_full == checker->nbr_of_philo)
		printf("The simulation was successful\n");
	else
		printf("The simulation was failed\n");
	clear_stop(philo, checker, i);
}
