/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:25:25 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/08/08 13:52:47 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strdup(const char *s1)
{
	char	*s;

	s = malloc(ft_strlen(s1) + 1);
	if (s == 0)
		return (0);
	ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	return (s);
}
