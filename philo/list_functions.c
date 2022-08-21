/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:52:08 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/19 17:25:29 by pmoreno-         ###   ########.fr       */
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
	t_philo	*sig;

	sig = malloc(sizeof(t_philo));
	if (sig == 0)
		return (0);
	sig->philo = philo;
	sig->right = NULL;
	return (sig);
}

void	ft_lstadd_back(t_philo **philos, t_philo *new_philo)
{
	t_philo	*sig;

	if (*philos)
	{
		sig = ft_lstlast(*philos);
		sig->right = new_philo;
	}
	else
		*philos = new_philo;
}
