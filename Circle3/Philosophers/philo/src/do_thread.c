/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:58:07 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/02 18:58:07 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	create_thread(t_table *table)
{
	long	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_create(&table->philos[i].thread,
			NULL, &routine, &table->philos[i]);
		i++;
	}
}

void	join_thread(t_table *table)
{
	long	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}
