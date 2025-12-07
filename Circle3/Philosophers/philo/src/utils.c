/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:46:44 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/24 09:06:47 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_atol(char *str)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		n = n * 10 + (str[i++] - '0');
	}
	return (n);
}

// TIME FUNCS
size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t m)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < m)
		usleep(500);
	return (0);
}
