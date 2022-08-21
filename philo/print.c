/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:23:06 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/21 12:32:51 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_eat(char *str, t_philo *philo)
{
	int	time;

	time = ft_get_time();
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->death == 0)
		printf("\033[1;32m\t%d \033[0m %d\t  %s\n",
			time - philo->data->initial_time, philo->philo, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_print_sleep(char *str, t_philo *philo)
{
	int	time;

	time = ft_get_time();
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->death == 0)
		printf("\033[1;35m\t%d \033[0m %d\t  %s\n",
			time - philo->data->initial_time, philo->philo, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_print_think(char *str, t_philo *philo)
{
	int	time;

	time = ft_get_time();
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->death == 0)
		printf("\033[1;34m\t%d \033[0m %d\t  %s\n",
			time - philo->data->initial_time, philo->philo, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_print_die(char *str, t_philo *philo)
{
	int	time;

	time = ft_get_time();
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->death == 0)
		printf("\033[1;31m\t%d  %d\t  %s\033[0m\n",
			time - philo->data->initial_time, philo->philo, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_print_fork(char *str, t_philo *philo)
{
	int	time;

	time = ft_get_time();
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->death == 0)
		printf("\033[33m\t%d \033[0m %d\t  %s\n",
			time - philo->data->initial_time, philo->philo, str);
	pthread_mutex_unlock(&philo->data->print);
}
