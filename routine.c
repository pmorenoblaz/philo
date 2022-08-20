/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:25:21 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/20 19:00:11 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_eating(t_philo *philo)
{
	while (1)
	{
		if (philo->data->death == 1)
			break ;
		if (ft_get_time() - philo->last_meal >= philo->data->time_eat)
			break ;
		usleep(500);
	}
	philo->meals++;
	if (philo->meals >= philo->data->philo_meals
		&& philo->data->philo_meals != -1)
	{
		pthread_mutex_lock(&philo->data->mutex);
		philo->data->nsatisfied++;
		pthread_mutex_unlock(&philo->data->mutex);
		philo->is_hungry = 0;
	}
}

int	ft_only_one_philo(t_philo *philo)
{
	if (philo->data->nphilos == 1)
	{
		philo->last_meal = ft_get_time();
		while (ft_get_time() - philo->last_meal
			< philo->data->time_die)
			usleep(1000);
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	return (0);
}

int	ft_eat(t_philo *philo)
{
	get_right_fork(philo);
	if (ft_only_one_philo(philo) == 1)
		return (1);
	get_left_fork(philo);
	pthread_mutex_lock(&philo->data->life);
	ft_print_action("is eating", philo);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->data->life);
	usleep(philo->data->time_eat * 500);
	ft_philo_eating(philo);
	ft_unlock_forks(philo);
	return (0);
}

void	ft_philo_sleeping(t_philo *philo)
{
	int	time;

	time = ft_get_time();
	ft_print_action("is sleeping", philo);
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
		if (data->death == 1 || ph->is_hungry == 0)
		{
			// ft_print_action("estoy lleno", ph);
			break ;
		}
		if (ft_eat(ph))
			break ;
		ft_philo_sleeping(ph);
		ft_print_action("is thinking", ph);
	}
	return (0);
}
