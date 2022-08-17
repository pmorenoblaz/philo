/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:52:08 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/17 18:55:28 by pmoreno-         ###   ########.fr       */
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
	t_philo	*sig;

	sig = malloc(sizeof(t_philo));
	if (sig == 0)
		return (0);
	sig->philo = philo;
	sig->right = NULL;
	return (sig);
}

void	ft_lstadd_back(t_philo **philos, t_philo *new_philo)
{
	t_philo	*sig;

	if (*philos)
	{
		sig = ft_lstlast(*philos);
		sig->right = new_philo;
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

void	ft_link_philos(t_philo *philo)
{
	t_philo	*sig;

	sig = philo;
	while (sig)
	{
		if (sig->right)
			sig->right->left = sig;
		else
		{
			philo->left = sig;
			sig->right = philo;
			break ;
		}
		sig = sig->right;
	}
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
	// while (1)
	// {
	// 	if (args->alive == false || ph->is_hungry == false)
	// 		break ;
	// 	if (ft_eating(ph))
	// 		break ;
	// 	ft_sleeping(ph);
	// 	ft_print("is thinking", ph);
	// }
	return (NULL);
}

int	ft_destroy_mutex(t_philo *philo, t_philos_data *data)
{
	t_philo	*sig;

	pthread_mutex_destroy(&data->mutex);
	sig = philo;
	while (sig)
	{
		pthread_mutex_destroy(&sig->fork);
		sig = sig->right;
	}
	return (0);
}

int	ft_join_threads(t_philo *philo)
{
	t_philo	*sig;

	sig = philo;
	while (sig)
	{
		pthread_join(sig->thread, NULL);
		sig = sig->right;
	}
	return (0);
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
