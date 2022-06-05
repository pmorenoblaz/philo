/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:43:01 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/06/05 11:57:11 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isalpha(char *str)
{
	int i;

    i = 0;
    while (str[i])
    {
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
			return (1);
	}
	return (0);
}

int	ft_check_args(char **argv, t_philos_data *data)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isalpha(argv[i]) == 1)
		{
			free(data);
			return (1);
		}
		i++;
	}
	return (0);
}