/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:00:00 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/16 17:41:33 by pmoreno-         ###   ########.fr       */
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

t_philo	*ft_lstlast(t_philo *lst)
{
	t_philo	*sig;

	sig = lst;
	if (!lst)
		return (0);
	while (sig->right != 0)
		sig = sig->right;
	return (sig);
}

t_philo	*ft_lstnew(int philo)
{
	t_philo	*aux;

	aux = malloc(sizeof(t_philo));
	if (aux == 0)
		return (0);
	aux->philo = philo;
	aux->right = NULL;
	return (aux);
}

void	ft_lstadd_back(t_philo **philos, t_philo *new_philo)
{
	t_philo	*aux;

	if (*philos)
	{
		aux = ft_lstlast(*philos);
		aux->right = new_philo;
	}
	else
		*philos = new_philo;
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
			free(philos);
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
	t_philo			*philos;
	t_philos_data	*data;

	atexit(leaks);
	philos = 0;
	data = malloc(sizeof(t_philos_data));
	if (!data)
		return (1);
	init_philos_data(&data);
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
		ft_start_philos(&philos, data);
	}
	free(data);
	return (0);
}
