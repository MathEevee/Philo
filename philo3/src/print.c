/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:19:36 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/20 13:42:06 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	{
		while (i <= checker->nbr_of_philo - 1)
		{
			if (philo[i]->status == DEAD)
				break ;
			i++;
		}
		printf("philo %d died\n");
	}
	clear_stop(philo, checker, i);
}

void	print_action(t_checker *checker, int i, t_philo *philo)
{
	long long int	diff;

	gettimeofday(&checker->end, NULL);
	diff = calc_time(checker);
	printf("%llu : philo %d ", diff, i + 1);
	if (philo[i].status == TAKE_FORK_R)
		printf("take a fork\n");
	if (philo[i].status == EAT)
		printf("is eating\n");
	if (philo[i].status == SLEEP)
		printf("is sleeping\n");
	if (philo[i].status == THINK)
		printf("is sleeping\n");
	if (philo[i].status == DEAD)
	{
		printf("died\n");
		checker->finish = END;
		init_philo_end(philo, checker);
		return ;
	}
	philo[i].status = NOTHING;
}
