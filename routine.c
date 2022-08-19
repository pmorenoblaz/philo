/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:25:21 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/19 19:15:28 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_keep_eating(t_philo *philo)
{
	while (1)
	{
		if (philo->data->alive == false)
			break ;
		if (ft_get_time() - philo->last_meal >= philo->data->time_eat)
			break ;
		usleep(500);
	}
	philo->meals++;
	if (philo->meals >= philo->data->philo_meals && philo->data->philo_meals != -1)
	{
		// pthread_mutex_lock(&philo->data->mutex_satisfaction);
		philo->data->nsatisfied++;
		// pthread_mutex_unlock(&philo->data->mutex_satisfaction);
		philo->is_hungry = false;
	}
}

int	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_action("has taken a fork (right)", philo);
	if (philo->data->nphilos == 1)
	{
		philo->last_meal = ft_get_time();
		pthread_mutex_unlock(&philo->fork);
		while (ft_get_time() - philo->last_meal
			< philo->data->time_die)
			usleep(1000);
		return (1);
	}
	pthread_mutex_lock(&philo->left->fork);
	print_action("has taken a fork (left)", philo);
	pthread_mutex_lock(&philo->data->life);
	print_action("is eating", philo);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->data->life);
	usleep(philo->data->time_eat * 500);
	ft_keep_eating(philo);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->left->fork);
	return (0);
}

void	ft_sleeping(t_philo *philo)
{
	int	time;

	time = ft_get_time();
	print_action("is sleeping", philo);
	usleep(philo->data->time_sleep * 500);
	while (1)
	{
		if (ft_get_time() - time >= philo->data->time_sleep)
			break ;
		usleep(500);
	}
	return ;
}

void	*ft_routine(void *philo)
{
	t_philo			*ph;
	t_philos_data	*data;

	ph = (t_philo *)philo;
	data = ph->data;
	ph->last_meal = ft_get_time();
	if (ph->philo % 2 == 0 || (ph->philo == data->nphilos && ph->philo != 1))
		usleep(data->time_eat * 500);
	while (1)
	{
		// printf("HOLA soy %d\n", ph->philo);
		if (data->alive == false || ph->is_hungry == false)
			break ;
		if (ft_eating(ph))
			break ;
		ft_sleeping(ph);
		print_action("is thinking", ph);
	}
	return (0);
}