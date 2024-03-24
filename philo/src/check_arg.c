/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:06:38 by matde-ol          #+#    #+#             */
/*   Updated: 2024/03/24 12:35:51 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_is_digit(char **av)
{
	int	i;
	int	j;

	j = 1;
	while(av[j] != NULL)
	{
		i = 0;
		while(av[j][i] != '\0')
		{
			if (!(av[j][i] >= '0' && av[j][i] <= '9'))
			{
				write(2, "Arguments are not valid\n", 24);
				return (-1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

static int	check_arg_nbr(int ac)
{
	if (ac <= 4)
	{
		write(2, "Too few arguments\n", 18);
		return (-1);
	}
	else if (ac >= 7)
	{
		write(2, "Too many arguments\n", 19);
		return (-1);
	}
	else
		return (0);
}

static int	check_data(char **av)
{
	long long int	ref;
	int				i;

	ref = 0;
	i = 1;
	while (av[i] != NULL)
	{
		ref = ft_atoll(av[i]);
		if (ref <= 0 || ref > 2147483647)
		{
			write(2, "Invalid number\n", 15);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_arg(int ac, char **av)
{
	if (check_arg_nbr(ac) == -1)
		return (-1);
	if (check_is_digit(av) == -1)
		return (-1);
	if (check_data(av) == -1)
		return (-1);
	return (0);
}
