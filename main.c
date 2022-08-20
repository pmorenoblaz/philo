/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:00:00 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/20 18:23:53 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
- 0 filosofos
- tiempo 0

*/

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
	if (ft_add_values(argv, data) == -1)
	{
		printf("Bad arguments\n");
		free(data);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philos_data	*data;

	if (ft_check_args(argc) == 0)
		return (0);
	data = malloc(sizeof(t_philos_data));
	if (!data)
		return (1);
	data->list = 0;
	if (init_data(&data, argv) == 1)
		return (1);
	if (ft_start_philos(&data->list, data) == 0)
		ft_init_philosophers(data->list, data);
	ft_link_philos(data->list);
	data->initial_time = ft_get_time();
	ft_init_threads(data->list, &ft_routine);
	ft_check_if_philo_died(data->list);
	ft_join_threads(data->list);
	ft_destroy_mutex(data->list);
	ft_free_philosophers(data->list);
	free(data);
	return (0);
}
