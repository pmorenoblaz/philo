/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:59:56 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/06/05 11:26:29 by pmoreno-         ###   ########.fr       */
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

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				id;
	int				is_available;
	struct s_fork	*next;
}	t_fork;

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
	bool			hungry;
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
	struct s_fork	*right_fork;
    struct s_fork	*left_fork;
	struct s_philo	*next;
    pthread_t		thread;
    pthread_mutex_t	fork;
}	t_philo;

 



#endif