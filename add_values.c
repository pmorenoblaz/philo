/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:08:50 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/20 16:53:17 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Incorrect number of argv\n");
		printf("Usage: ./philo number_of_philo time_to_die ");
		printf("time_to_eat time_to_sleep [meals_per_philo]\n");
		return (0);
	}
	return (1);
}

int	ft_valid_args(char	*data)
{
	int		i;

	i = -1;
	while (data[++i])
	{
		if (data[i] < '0' || data[i] > '9')
			return (-1);
	}
	return (ft_atoi(data));
}

int	ft_check_values(t_philos_data *data)
{
	if ((*data).nphilos == -1 || (*data).time_die == -1
		|| (*data).time_eat == -1 || (*data).time_sleep == -1
		|| (*data).initial_time == -1)
		return (-1);
	return (0);
}

int	ft_add_values(char **argv, t_philos_data **data)
{
	(*data)->nphilos = ft_valid_args(argv[1]);
	(*data)->time_die = ft_valid_args(argv[2]);
	(*data)->time_eat = ft_valid_args(argv[3]);
	(*data)->time_sleep = ft_valid_args(argv[4]);
	if (argv[5])
		(*data)->philo_meals = ft_valid_args(argv[5]);
	return (ft_check_values(*data));
}
