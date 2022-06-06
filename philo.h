/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:59:56 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/06/06 20:19:31 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_philos_data
{
	int				nphilos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				philo_meals;
	int				nsatisfied;
	int				death;
    int             alive;
	int				hungry;
	int				initial_time;
	struct s_philo	**list;
	pthread_mutex_t	mutex;
	struct timeval	start;
}	t_philos_data;

typedef struct s_philo
{
	int				philo;
	int				meals;
	int				last_meal;
	int			    is_hungry;
	struct s_philo	*left;
	struct s_philo	*right;
    pthread_t		thread;
    pthread_mutex_t	fork;
}	t_philo;

#endif