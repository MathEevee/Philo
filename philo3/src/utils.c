/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:24:00 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/17 16:08:29 by matde-ol         ###   ########.fr       */
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

unsigned long long int	calc_time(t_data *data)
{
	unsigned long long int	tmp_start;
	unsigned long long int	tmp_end;
	unsigned long long int	diff;

	gettimeofday(&data->end, NULL);
	tmp_end = (data->end.tv_sec * MS_TO_SEC + data->end.tv_usec) / 1000;
	tmp_start = (data->start.tv_sec * MS_TO_SEC + data->start.tv_usec) / 1000;
	diff = tmp_end - tmp_start;
	return (diff);
}

unsigned long long int	calc_time_philo(t_data *data)
{
	unsigned long long int	tmp_start;
	unsigned long long int	tmp_end;
	unsigned long long int	diff;

	gettimeofday(&data->end, NULL);
	tmp_end = (data->philo[data->i]->end_philo.tv_sec * MS_TO_SEC \
				+ data->philo[data->i]->end_philo.tv_usec) / 1000;
	tmp_start = (data->philo[data->i]->start_philo.tv_sec * MS_TO_SEC \
				+ data->philo[data->i]->start_philo.tv_usec) / 1000;
	diff = tmp_end - tmp_start;
	return (diff);
}