/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:52:08 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/17 18:01:38 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	free_philosophers(t_philo **philos)
{
	t_philo	*sig;

	sig = (*philos);
	while (sig)
	{
		sig = (*philos)->right;
		free((*philos));
		(*philos) = sig;
	}
	free(*philos);
}

void	print_philos(t_philo *philo)
{
	t_philo	*sig;

	sig = philo;
	while (sig)
	{
		printf("\n------------------\n");
		printf("ID: %d \n", sig->philo);
		printf("Meals: %d \n", sig->meals);
		printf("Last meal: %d \n", sig->last_meal);
		printf("Is hungry?: %d \n", sig->is_hungry);
		printf("Mutex: %p\n", &sig->fork);
		sig = sig->right;
	}
}

void	*ft_routine(void *philo)
{
	t_philo			*ph;
	t_philos_data	*args;

	ph = (t_philo *)philo;
	args = ph->data;
	ph->last_meal = ft_get_time();
	if (ph->philo % 2 == 0 || (ph->philo == args->nphilos && ph->philo != 1))
		usleep(args->time_eat * 500);
	while (1)
	{
		if (args->alive == false || ph->is_hungry == false)
			break ;
		// if (ft_eating(ph))
		// 	break ;
		// ft_sleeping(ph);
		// ft_print("is thinking", ph);
	}
	return (NULL);
}

void	ft_init_threads(t_philo *philo, void *routine)
{
	t_philo	*sig;

	sig = philo;
	while (sig)
	{
		pthread_create(&sig->thread, NULL, routine, sig);
		sig = sig->right;
	}
	print_philos(philo);
}

void	ft_init_philosophers(t_philo *philo, t_philos_data *data)
{
	t_philo	*sig;

	sig = philo;
	while (sig)
	{
		sig->is_hungry = 1;
		sig->last_meal = 0;
		sig->meals = 0;
		pthread_mutex_init(&sig->fork, NULL);
		sig->data = data;
		sig = sig->right;
	}
	print_philos(philo);
}
