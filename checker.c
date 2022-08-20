/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:09:10 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/20 18:18:42 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_satisfied_philos(t_philo *philo, t_philos_data *data)
{
	if (philo->data->philo_meals != -1)
	{
		if (philo->is_hungry == 0)
			data->nsatisfied++;
		if (philo->philo == data->nphilos && data->nsatisfied != data->nphilos)
			data->nsatisfied = 0;
	}
}

void	ft_die_philo_die(t_philo *philo)
{
	ft_print_action("died", philo);
	philo->data->death = 1;
}

void	ft_check_if_philo_died(t_philo *philos)
{
	t_philo	*sig;

	sig = philos;
	if (sig->data->nphilos == 1)
		usleep(sig->data->time_die * 500);
	while (1)
	{
		pthread_mutex_lock(&sig->data->life);
		if (sig->data->death == 1
			|| sig->data->nsatisfied == sig->data->nphilos)
		{
			pthread_mutex_unlock(&sig->data->life);
			break ;
		}
		if (ft_get_time() - sig->last_meal >= sig->data->time_die)
		{
			// ft_die_philo_die(sig);
			ft_print_action("died",  sig);
			sig->data->death = 1;
		}
		pthread_mutex_unlock(&sig->data->life);
		// ft_check_satisfied_philos(sig, sig->data);
		sig = sig->right;
		usleep(300);
		if (sig == philos->left && sig->data->nphilos > 1)
			usleep(1000);
	}
}
