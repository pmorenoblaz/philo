/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:21:41 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/19 17:22:50 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			free_philosophers(*philos);
			free(data);
			return (1);
		}
		else
			ft_lstadd_back(philos, aux);
		i++;
	}
	return (0);
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