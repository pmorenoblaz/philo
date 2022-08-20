/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:32:19 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/20 15:36:39 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    checker(t_philo *philos)
{
    t_philo *sig;

    sig = philos;
    if (sig->data->nphilos == 1)
		usleep(sig->data->time_die * 500);
    while (1)
    {
        pthread_mutex_lock(&sig->data->life);
		if (sig->data->alive == 0 || sig->data->nsatisfied == sig->data->nphilos)
		{
			pthread_mutex_unlock(&sig->data->life);
			break ;
		}
		if (ft_get_time() - sig->last_meal >= sig->data->time_die)
		{
			print_action("died", sig);
			sig->data->alive = 0;
		}
		pthread_mutex_unlock(&sig->data->life);
		sig = sig->right;
		usleep(300);
		if (sig == philos->left && sig->data->nphilos > 1)
			usleep(1000);
    }
}