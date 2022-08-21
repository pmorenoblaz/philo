/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:00:00 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/21 12:32:18 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leaks(void)
{
	system("leaks philo");
}

int	init_data(t_philos_data **data, char **argv)
{
	(*data)->initial_time = 0;
	(*data)->nphilos = -1;
	(*data)->time_die = -1;
	(*data)->time_eat = -1;
	(*data)->time_sleep = -1;
	(*data)->philo_meals = -1;
	(*data)->death = 0;
	(*data)->nsatisfied = 0;
	if (ft_add_values(argv, data) == -1)
	{
		free(*data);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philos_data	*data;
	t_philo			*philos;

	philos = 0;
	if (ft_check_args(argc) == 0)
		return (0);
	data = malloc(sizeof(t_philos_data));
	if (!data)
		return (1);
	if (init_data(&data, argv) == 1)
		return (1);
	if (ft_start_philos(&philos, data) == 0)
		ft_init_philosophers(philos, data);
	ft_link_philos(philos);
	data->initial_time = ft_get_time();
	ft_init_threads(philos, &ft_routine);
	ft_check_if_philo_died(philos);
	ft_join_threads(philos);
	ft_destroy_mutex(philos);
	ft_free_philosophers(philos);
	free(data);
	return (0);
}
