/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:58:46 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/16 16:52:23 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *ph)
{
	t_philo			*philo;
	t_philos_data	*data;

	philo = (t_philo *)ph;
	data = 0;
	data->nphilos = 8;
	philo->last_meal = ft_get_time();
	if (philo->philo % 2 == 0
		|| (philo->philo == data->nphilos && philo->philo != 1))
		usleep(data->time_eat * 500);
	while (1)
	{
		if (data->alive == false || philo->is_hungry == false)
			break ;
		// if (ft_eating(ph))
		// 	break ;
		// ft_sleeping(ph);
		ft_putstr_fd(ft_itoa(philo->philo), 1);
		write (1, "is thinking\n", 12);
	}
	return (NULL);
}
