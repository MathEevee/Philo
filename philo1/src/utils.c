/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:24:00 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/21 09:50:18 by matde-ol         ###   ########.fr       */
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

unsigned long long int	calc_time(t_checker *checker)
{
	unsigned long long int	tmp_start;
	unsigned long long int	tmp_end;
	unsigned long long int	diff;

	gettimeofday(&checker->end, NULL);
	tmp_end = (checker->end.tv_sec * MS_TO_SEC\
			+ checker->end.tv_usec) / 1000;
	tmp_start = (checker->start.tv_sec * MS_TO_SEC\
			+ checker->start.tv_usec) / 1000;
	diff = tmp_end - tmp_start;
	return (diff);
}

unsigned long long int	calc_time_philo(t_philo *philo)
{
	unsigned long long int	tmp_start;
	unsigned long long int	tmp_end;
	unsigned long long int	diff;

	gettimeofday(&philo->end_philo, NULL);
	tmp_end = (philo->end_philo.tv_sec * MS_TO_SEC \
				+ philo->end_philo.tv_usec);
	tmp_start = (philo->start_philo.tv_sec * MS_TO_SEC \
				+ philo->start_philo.tv_usec);
	diff = tmp_end - tmp_start;
	return (diff);
}