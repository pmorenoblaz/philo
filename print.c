/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:23:06 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/19 18:58:31 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_values(t_philos_data *data)
{
	printf("Number of philos: %d \n", data->nphilos);
	printf("Time to die: %d \n", data->time_die);
	printf("Time to eat: %d \n", data->time_eat);
	printf("Time to sleep: %d \n", data->time_sleep);
	if (data->philo_meals != -1)
		printf("Number of meals: %d \n", data->philo_meals);
	printf("Initial time: %d\n", data->initial_time);
	printf("Mutex: %p\n", &data->mutex);
}

void	print_philos(t_philo *philo)
{
	t_philo	*sig;
	t_philo	*aux;

	aux = philo;
	while (aux)
	{
		if (aux->right)
			sig = aux->right;
		printf("\n------------------\n");
		printf("ID: %d \n", aux->philo);
		printf("Meals: %d \n", aux->meals);
		printf("Last meal: %d \n", aux->last_meal);
		printf("Is hungry?: %d \n", aux->is_hungry);
		printf("Mutex: %p\n", &aux->fork);
		aux = sig;
		if (sig->philo == 1)
			return ;
	}
}

void	print_action(char *str, t_philo *philo)
{
	int	time;

	time = ft_get_time();
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->alive == true)
		printf("\t%d ms %d\t%s\n", time - philo->data->initial_time, philo->philo, str);
	pthread_mutex_unlock(&philo->data->print);
}