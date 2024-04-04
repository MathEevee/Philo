/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:24:00 by matde-ol          #+#    #+#             */
/*   Updated: 2024/04/04 10:21:39 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

ssize_t	ft_atoll(char *nbr)
{
	int		i;
	ssize_t	sum;
	int		neg;

	i = 0;
	sum = 0;
	neg = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			neg = 1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		sum = sum * 10 + (nbr[i] - 48);
		i++;
	}
	if (neg == 1)
		return (-sum);
	return (sum);
}

size_t	calc_time(t_data_simulation *d_sim)
{
	size_t	tmp_start;
	size_t	tmp_end;
	ssize_t	diff;

	gettimeofday(&d_sim->gtimer->end, NULL);
	tmp_end = (d_sim->gtimer->end.tv_sec * SEC_MS \
			+ d_sim->gtimer->end.tv_usec) / MS_USEC;
	tmp_start = (d_sim->gtimer->start.tv_sec * SEC_MS \
			+ d_sim->gtimer->start.tv_usec) / MS_USEC;
	diff = tmp_end - tmp_start;
	return (diff);
}

size_t	calc_time_philo(t_philo *philo)
{
	size_t	tmp_start;
	size_t	tmp_end;
	ssize_t	diff;

	gettimeofday(&philo->ptime->end, NULL);
	tmp_end = (philo->ptime->end.tv_sec * SEC_MS \
				+ philo->ptime->end.tv_usec) / MS_USEC;
	tmp_start = (philo->ptime->start.tv_sec * SEC_MS \
				+ philo->ptime->start.tv_usec) / MS_USEC;
	diff = tmp_end - tmp_start;
	return (diff);
}
