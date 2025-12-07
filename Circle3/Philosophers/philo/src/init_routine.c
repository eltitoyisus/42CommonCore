/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:52:27 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/11 08:16:51 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init(t_table *table, t_philo_args args)
{
	long	i;

	table->num_philos = args.number_philo;
	table->time_to_die = args.time_to_die;
	table->time_to_eat = args.time_to_eat;
	table->time_to_sleep = args.time_to_sleep;
	table->num_eats = args.repeat;
	table->start_time = get_current_time();
	table->someone_die = 0;
	pthread_mutex_init(&table->death_mutex, NULL);
	table->philos = malloc_prevent(sizeof(t_philo) * table->num_philos);
	table->forks = malloc_prevent(sizeof(pthread_mutex_t) * table->num_philos);
	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].eat_count = 0;
		table->philos[i].last_eat_time = table->start_time;
		table->philos[i].table = table;
		table->philos[i].fork_left = &table->forks[i];
		table->philos[i].fork_right
			=&table->forks[(i + 1) % table->num_philos];
		i++;
	}
}

void	do_routine(t_table *table)
{
	pthread_t	monitor;

	mutex_init(table);
	pthread_create(&monitor, NULL, &monitor_routine, table);
	create_thread(table);
	join_thread(table);
	pthread_join(monitor, NULL);
	mutex_destroy(table);
}
