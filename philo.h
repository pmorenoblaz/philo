/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:59:56 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/17 17:59:10 by pmoreno-         ###   ########.fr       */
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
	int				alive;
	int				hungry;
	int				initial_time;
	struct s_philo	*list;
	pthread_mutex_t	mutex;
	struct timeval	start;
}	t_philos_data;

typedef struct s_philo
{
	int						philo;
	int						meals;
	int						last_meal;
	int						is_hungry;
	struct s_philo			*right;
	pthread_t				thread;
	pthread_mutex_t			fork;
	struct s_philos_data	*data;
}	t_philo;

char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_routine(void *ph);
int		ft_get_time(void);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);

/* main.c */
void	init_data(t_philos_data **data);

/* add_values.c */
int		ft_check_args(int argc);
void	print_values(t_philos_data *data);
int		ft_valid_args(char	*data);
int		add_values(char **argv, t_philos_data **data);

/* list_functions.c */
t_philo	*ft_lstlast(t_philo *lst);
t_philo	*ft_lstnew(int philo);
void	ft_lstadd_back(t_philo **philos, t_philo *new_philo);
void	free_philosophers(t_philo **philos);
void	ft_init_philosophers(t_philo *philo, t_philos_data *data);
void	print_philos(t_philo *philo);

#endif