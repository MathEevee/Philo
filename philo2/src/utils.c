/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:54:05 by matde-ol          #+#    #+#             */
/*   Updated: 2024/02/17 10:00:59 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoll(char *nbr)
{
	long long int			sum;
	int						i;
	int						n;

	i = 0;
	sum = 0;
	n = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	while(nbr[i] != '\0')
	{
		sum = sum * 10 + (nbr[i] - 48);
		i++;
	}
	return (sum);
}

unsigned long long int	calc_time(t_data *data)
{
	unsigned long long int	tmp_start;
	unsigned long long int	tmp_end;
	unsigned long long int	diff;

	gettimeofday(&data->end, NULL);
	tmp_end = (data->end.tv_sec * 1000000 + data->end.tv_usec) / 1000;
	tmp_start = (data->start.tv_sec * 1000000 + data->start.tv_usec) / 1000;
	diff = tmp_end - tmp_start;
	return (diff);
}
