/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:00:00 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/16 17:13:06 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leaks(void)
{
	system("leaks philo");
}

void	init_philos_data(t_philos_data **data)
{
	(*data)->initial_time = 0;
	(*data)->nphilos = -1;
	(*data)->time_die = -1;
	(*data)->time_eat = -1;
	(*data)->time_sleep = -1;
	(*data)->philo_meals = -1;
}

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_philos_data	*data;

	atexit(leaks);
	philos = 0;
	data = malloc(sizeof(t_philos_data));
	init_philos_data(&data);
	print_values(data);
	if (ft_check_args(argc) == 0)
	{
		free(data);
		return (0);
	}
	else
	{
		if (add_values(argv, &data) == -1)
		{
			printf("Bad arguments\n");
			free(data);
			return (0);
		}
		print_values(data);
	}
	free(data);
	return (0);
}
