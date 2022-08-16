/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:00:00 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/16 16:31:52 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leaks(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_philos_data	*data;

	atexit(leaks);
	philos = 0;
	data = malloc(sizeof(t_philos_data));
	if (ft_check_args(argc) == 0)
	{
		free(data);
		return (0);
	}
	else
	{
		if (add_values(argv, &data) == -1)
		{
			printf("Bad arguments\n");
			free(data);
			return (0);
		}
		print_values(data);
	}
	free(data);
	return (0);
}
