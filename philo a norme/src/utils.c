/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:24:00 by matde-ol          #+#    #+#             */
/*   Updated: 2024/03/24 13:39:13 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	ft_atoll(char *nbr)
{
	int				i;
	long long int	sum;
	int				neg;

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

unsigned long long int	calc_time(t_data_simulation *d_sim)
{
	unsigned long long int	tmp_start;
	unsigned long long int	tmp_end;
	long long int			diff;

	gettimeofday(&d_sim->gtimer->end, NULL);
	tmp_end = (d_sim->gtimer->end.tv_sec * SEC_MS\
			+ d_sim->gtimer->end.tv_usec) / MS_USEC;
	tmp_start = (d_sim->gtimer->start.tv_sec * SEC_MS\
			+ d_sim->gtimer->start.tv_usec) / MS_USEC;
	diff = tmp_end - tmp_start;
	return (diff);
}

unsigned long long int	calc_time_philo(t_philo *philo)
{
	unsigned long long int	tmp_start;
	unsigned long long int	tmp_end;
	long long int	diff;

	gettimeofday(&philo->ptime->end, NULL);
	tmp_end = (philo->ptime->end.tv_sec * 1000\
				+ philo->ptime->end.tv_usec / 1000);
	tmp_start = (philo->ptime->start.tv_sec * 1000\
				+ philo->ptime->start.tv_usec / 1000);
	diff = tmp_end - tmp_start;
	return (diff);
}
