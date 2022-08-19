/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:20:28 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/19 18:59:33 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_threads(t_philo *philo, void *routine)
{
	t_philo	*sig;
	t_philo	*aux;

	aux = philo;
	while (aux)
	{
		if (aux->right)
			sig = aux->right;
		pthread_create(&sig->thread, NULL, routine, aux);
		aux = sig;
		if (sig->philo == 1)
			return ;
	}
}

int	ft_join_threads(t_philo *philo)
{
	t_philo	*sig;
	t_philo	*aux;

	aux = philo;
	while (aux)
	{
		if (aux->right)
			sig = aux->right;
		pthread_join(sig->thread, NULL);
		// printf("JOIN soy %d\n", aux->philo);
		aux = sig;
		if (sig->philo == 1)
			return (0);
	}
	return (0);
}

int	ft_destroy_mutex(t_philo *philo)
{
	t_philo	*sig;
	t_philo	*aux;

	aux = philo;
	while (aux)
	{
		if (aux->right)
			sig = aux->right;
		pthread_mutex_destroy(&sig->fork);
		// printf("ADIOS soy %d\n", aux->philo);
		aux = sig;
		if (sig->philo == 1)
			return (0);
	}
	return (0);
}