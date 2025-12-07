/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:38:30 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/10 20:45:05 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	mutex_init(t_table *table)
{
	long	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	mutex_destroy(t_table *table)
{
	long	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->death_mutex);
	free_philo(table);
}
