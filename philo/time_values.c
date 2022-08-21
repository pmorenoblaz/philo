/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:51:59 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/18 19:29:52 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_time(void)
{
	int				t;
	struct timeval	time;

	gettimeofday(&time, NULL);
	t = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (t);
}
