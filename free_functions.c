/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:24:42 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/20 16:50:00 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philosophers(t_philo *philos)
{
	t_philo	*sig;
	t_philo	*aux;
	int		i;

	aux = philos;
	i = 1;
	while (i < aux->data->nphilos)
	{
		sig = aux->right;
		free(aux);
		aux = sig;
		i++;
	}
	free(aux);
}
