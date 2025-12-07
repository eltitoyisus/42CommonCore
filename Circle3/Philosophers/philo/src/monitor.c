/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:05:08 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/13 10:14:58 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	handle_philo_death(t_table *table, int i, size_t current_time)
{
	printf("%ld %ld died\n",
		current_time - table->start_time, table->philos[i].id);
	table->someone_die = 1;
}

int	check_philo_state(t_table *table, int i, int *all_ate_enough)
{
	size_t	current_time;

	current_time = get_current_time();
	pthread_mutex_lock(&table->death_mutex);
	if (table->someone_die)
	{
		pthread_mutex_unlock(&table->death_mutex);
		return (1);
	}
	if (current_time - table->philos[i].last_eat_time
		> (size_t)table->time_to_die)
	{
		handle_philo_death(table, i, current_time);
		pthread_mutex_unlock(&table->death_mutex);
		return (1);
	}
	if (table->num_eats > 0 && table->philos[i].eat_count < table->num_eats)
		*all_ate_enough = 0;
	pthread_mutex_unlock(&table->death_mutex);
	return (0);
}

int	monitor_philos(t_table *table)
{
	int	i;
	int	all_ate_enough;

	i = 0;
	all_ate_enough = 1;
	while (i < table->num_philos)
	{
		if (check_philo_state(table, i, &all_ate_enough))
			return (1);
		i++;
	}
	if (table->num_eats > 0 && all_ate_enough)
	{
		pthread_mutex_lock(&table->death_mutex);
		table->someone_die = 1;
		pthread_mutex_unlock(&table->death_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (monitor_philos(table))
			return (NULL);
		ft_usleep(10);
	}
	return (NULL);
}
