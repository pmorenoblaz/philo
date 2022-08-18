/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:00:00 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/18 19:35:34 by pmoreno-         ###   ########.fr       */
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

void	init_data(t_philos_data **data)
{
	(*data)->initial_time = 0;
	(*data)->nphilos = -1;
	(*data)->time_die = -1;
	(*data)->time_eat = -1;
	(*data)->time_sleep = -1;
	(*data)->philo_meals = -1;
}

int	ft_start_philos(t_philo **philos, t_philos_data *data)
{
	int		i;
	t_philo	*aux;

	i = 0;
	while (i < data->nphilos)
	{
		aux = ft_lstnew(i + 1);
		if (!aux)
		{
			free_philosophers(*philos);
			free(data);
			return (1);
		}
		else
			ft_lstadd_back(philos, aux);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philos_data	*data;

	// atexit(leaks);
	data = malloc(sizeof(t_philos_data));
	if (!data)
		return (1);
	data->list = 0;
	init_data(&data);
	// print_values(data);
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
		if (ft_start_philos(&data->list, data) == 0)
			ft_init_philosophers(data->list, data);
		ft_link_philos(data->list);
		print_philos(data->list);
		data->initial_time = ft_get_time();
		ft_init_threads(data->list, &ft_routine);
		ft_join_threads(data->list);
		sleep(1);
	}
	free_philosophers(data->list);
	free(data);
	return (0);
}
