/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:52:08 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/16 17:56:02 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstlast(t_philo *lst)
{
	t_philo	*sig;

	sig = lst;
	if (!lst)
		return (0);
	while (sig->right != 0)
		sig = sig->right;
	return (sig);
}

t_philo	*ft_lstnew(int philo)
{
	t_philo	*aux;

	aux = malloc(sizeof(t_philo));
	if (aux == 0)
		return (0);
	aux->philo = philo;
	aux->right = NULL;
	return (aux);
}

void	ft_lstadd_back(t_philo **philos, t_philo *new_philo)
{
	t_philo	*aux;

	if (*philos)
	{
		aux = ft_lstlast(*philos);
		aux->right = new_philo;
	}
	else
		*philos = new_philo;
}
