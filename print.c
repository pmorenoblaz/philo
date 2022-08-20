/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:23:06 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/20 19:18:30 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	ft_print_values(t_philos_data *data)
// {
// 	printf("Number of philos: %d \n", data->nphilos);
// 	printf("Time to die: %d \n", data->time_die);
// 	printf("Time to eat: %d \n", data->time_eat);
// 	printf("Time to sleep: %d \n", data->time_sleep);
// 	if (data->philo_meals != -1)
// 		printf("Number of meals: %d \n", data->philo_meals);
// 	printf("Initial time: %d\n", data->initial_time);
// 	printf("Mutex: %p\n", &data->mutex);
// }

// void	ft_print_philos(t_philo *philo)
// {
// 	t_philo	*sig;
// 	t_philo	*aux;

// 	aux = philo;
// 	while (aux)
// 	{
// 		if (aux->right)
// 			sig = aux->right;
// 		printf("\n------------------\n");
// 		printf("ID: %d \n", aux->philo);
// 		printf("Meals: %d \n", aux->meals);
// 		printf("Last meal: %d \n", aux->last_meal);
// 		printf("Is hungry?: %d \n", aux->is_hungry);
// 		printf("Mutex: %p\n", &aux->fork);
// 		aux = sig;
// 		if (sig->philo == 1)
// 			return ;
// 	}
// }

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
