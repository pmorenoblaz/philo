/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:00:00 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/12 16:49:50 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leaks(void)
{
	system("leaks philo");
}

int	ft_check_args(int argc)
{
	if (argc < 4 || argc > 5)
	{
		printf("Incorrect number of argv\n");
		printf("Usage: ./philosophers number_of_philo time_to_die ");
		printf("time_to_eat time_to_sleep [meals_per_philo]\n");
		return (0);
	}
	return (1);
}

void	add_values(char **argv, t_philos_data **data)
{
	(*data)->time_die = ft_atoi(argv[1]);
	(*data)->time_eat = ft_atoi(argv[2]);
	(*data)->time_sleep = ft_atoi(argv[3]);
	if (argv[4])
		(*data)->philo_meals = ft_atoi(argv[4]);
}

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_philos_data	*data;

	atexit(leaks);
	philos = 0;
	data = malloc(sizeof(t_philos_data));
	if (ft_check_args(argc) == 0)
	{
		free(data);
		return (0);
	}
	else
	{
		add_values(argv, &data);
	}
	printf("%s", argv[0]);
	free(data);
	return (0);
}
