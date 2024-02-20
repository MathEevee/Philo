/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:58:06 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/20 13:20:25 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// void	send_end_msg(t_data *checker, int i)
// {
// 	if (checkerphilo[i].status == FULL)
// 		printf("Everyone ate\n");
// 	else
// 		printf("Simulation has failed\n");
// 	return ;
// }

// void	check_time_actions(t_philo *philo)
// {
// 	long long int	diff;

// 	gettimeofday(&philo[philo->index_of_philo].end_philo, NULL);
// 	diff = calc_time_philo(philo);
// 	if (philo[philo->index_of_philo].status == EAT)
// 	{
// 		if (diff + checkertime_to_eat > checkertime_to_die)
// 			init_data_death(data);
// 	}
// 	else if (checkerphilo[checkeri].status == THINK)
// 	{
// 		if (diff + checkertime_to_eat * 2 > checkertime_to_die)
// 			init_data_death(data);
// 	}
// 	else if (checkerphilo[checkeri].status == SLEEP)
// 	{
// 		if (diff + checkertime_to_eat * 3 > checkertime_to_die)
// 			init_data_death(data);
// 	}
// }
