/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:59:56 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/20 19:12:49 by pmoreno-         ###   ########.fr       */
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
	int				hungry;
	int				initial_time;
	struct s_philo	*list;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	life;
	struct timeval	start;
}	t_philos_data;

typedef struct s_philo
{
	int						philo;
	int						meals;
	int						last_meal;
	int						is_hungry;
	struct s_philo			*left;
	struct s_philo			*right;
	pthread_t				thread;
	pthread_mutex_t			fork;
	struct s_philos_data	*data;
}	t_philo;

char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_get_time(void);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);

/* main.c */
int		init_data(t_philos_data **data, char **argv);

/* add_values.c */
int		ft_check_args(int argc);
int		ft_valid_args(char	*data);
int		ft_add_values(char **argv, t_philos_data **data);

/* list_functions.c */
t_philo	*ft_lstlast(t_philo *lst);
t_philo	*ft_lstnew(int philo);
void	ft_lstadd_back(t_philo **philos, t_philo *new_philo);

/* philos.c */
int		ft_start_philos(t_philo **philos, t_philos_data *data);
void	ft_init_philosophers(t_philo *philo, t_philos_data *data);
void	ft_link_philos(t_philo *philos);

/* free_functions.c */
void	ft_free_philosophers(t_philo *philos);

/* print.c */
void	ft_print_values(t_philos_data *data);
void	ft_print_philos(t_philo *philo);
void	ft_print_action(char *str, t_philo *philo);

/* threads.c */
void	ft_init_threads(t_philo *philo, void *routine);
int		ft_join_threads(t_philo *philo);
int		ft_destroy_mutex(t_philo *philo);

/* routine.c */
void	*ft_routine(void *philo);
int		ft_eating(t_philo *philo);
void	ft_sleeping(t_philo *philo);

/* ft_checker.c */
void	ft_check_satisfied_philos(t_philo *philo, t_philos_data *data);
void	ft_die_philo_die(t_philo *philo);
void	ft_check_if_philo_died(t_philo *philos);

/* forks.c */
void	get_right_fork(t_philo *philo);
void	get_left_fork(t_philo *philo);
void	ft_unlock_forks(t_philo *philo);

/* print_actions.c */
void	ft_print_eat(char *str, t_philo *philo);
void	ft_print_sleep(char *str, t_philo *philo);
void	ft_print_think(char *str, t_philo *philo);
void	ft_print_fork(char *str, t_philo *philo);
void	ft_print_die(char *str, t_philo *philo);

#endif