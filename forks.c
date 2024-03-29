/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:44:47 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/21 12:05:54 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	ft_print_fork("has taken a fork (right)", philo);
}

void	get_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left->fork);
	ft_print_fork("has taken a fork (left)", philo);
}

void	ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->left->fork);
}
