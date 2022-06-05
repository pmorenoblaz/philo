/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:00:00 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/06/05 11:28:37 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    leaks()
{
    system("leaks philo");
}

int main(int argc, char **argv)
{
    t_philo         *philos;
    t_philos_data   *data;

    atexit(leaks);
    philos = 0;
    data = malloc(sizeof(t_philos_data));
    if (argc != 5)
        return (0);
    printf("%s", argv[0]);
    free(data);
    return (0);
}