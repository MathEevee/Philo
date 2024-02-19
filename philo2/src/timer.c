/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:58:06 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/19 16:09:11 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_data *checker, int i)
{
	long long int	diff;

	gettimeofday(&checkerend, NULL);
	diff = calc_time(data);
	printf("%llu : philo %d ", diff, i + 1);
	if (philo[i].status == TAKE_FORK_R)
		printf("take a fork\n");
	if (checkerphilo[i].status == EAT)
		printf("is eating\n");
	if (checkerphilo[i].status == SLEEP)
		printf("is sleeping\n");
	if (checkerphilo[i].status == THINK)
		printf("is sleeping\n");
	if (checkerphilo[i].status == DEAD)
	{
		printf("died\n");
		checkerfinish = END;
		return ;
	}
	checkerphilo[i].status = 0;
}

void	send_end_msg(t_data *checker, int i)
{
	if (checkerphilo[i].status == FULL)
		printf("Everyone ate\n");
	else
		printf("Simulation has failed\n");
	return ;
}

void	check_time_actions(t_data *checker)
{
	long long int	diff;

	gettimeofday(&checkerphilo[checkeri].end_philo, NULL);
	diff = calc_time_philo(data);
	if (checkerphilo[checkeri].status == EAT)
	{
		if (diff + checkertime_to_eat > checkertime_to_die)
			init_data_death(data);
	}
	else if (checkerphilo[checkeri].status == THINK)
	{
		if (diff + checkertime_to_eat * 2 > checkertime_to_die)
			init_data_death(data);
	}
	else if (checkerphilo[checkeri].status == SLEEP)
	{
		if (diff + checkertime_to_eat * 3 > checkertime_to_die)
			init_data_death(data);
	}
}

void	*check_action(void *arg)
{
	int				nbr_full_philo;
	int				i;
	t_data 			*checker;

	data = (t_data *) arg;
	nbr_full_philo = 0;
	i = 0;
	while (nbr_full_philo <= checkernbr_of_philo - 1)
	{
		if (checkerphilo[checkeri].status == FULL)
			nbr_full_philo++;
		if (checkerfinish == END)
			break ;
		if (checkerphilo[checkeri].status != 0)
			print_action(data, i);
		i++;
		if (i == checkernbr_of_philo)
			i = 0;
	}
	send_end_msg(data, i);
	return (NULL);
}
