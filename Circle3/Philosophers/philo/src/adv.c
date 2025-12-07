/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:54:45 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/28 14:11:26 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat / 2);
	while (1)
	{
		pthread_mutex_lock(&philo->table->death_mutex);
		if (philo->table->someone_die)
		{
			pthread_mutex_unlock(&philo->table->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->death_mutex);
		if (one_philo(philo))
			break ;
		if (die(philo))
			break ;
		x_routine(philo);
	}
	return (NULL);
}

void	x_routine(t_philo *philo)
{
	eat(philo);
	philo_sleep(philo);
	think(philo);
}

int	die(t_philo *philo)
{
	size_t	current_time;

	current_time = get_current_time();
	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->someone_die)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return (1);
	}
	if (current_time - philo->last_eat_time > (size_t)philo->table->time_to_die)
	{
		printf("%ld %ld died\n",
			current_time - philo->table->start_time, philo->id);
		philo->is_dead = 1;
		philo->table->someone_die = 1;
		pthread_mutex_unlock(&philo->table->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->death_mutex);
	return (0);
}

int	one_philo(t_philo *philo)
{
	size_t	current_time;

	current_time = get_current_time();
	if (philo->table->num_philos == 1)
	{
		printf("%ld %ld has taken a fork\n",
			get_current_time() - philo->table->start_time, philo->id);
		ft_usleep(philo->table->time_to_die);
		pthread_mutex_lock(&philo->table->death_mutex);
		philo->is_dead = 1;
		philo->table->someone_die = 1;
		pthread_mutex_unlock(&philo->table->death_mutex);
		return (1);
	}
	return (0);
}

void	adv_philo(t_philo_args args)
{
	t_table	*table;

	table = malloc_prevent(sizeof(t_table));
	if (!table)
		return ;
	if (args.number_philo <= 0 || args.time_to_die <= 0
		|| args.time_to_eat <= 0 || args.time_to_sleep <= 0
		|| args.repeat <= 0)
	{
		printf("Invalid input: all arguments must be positive numbers\n");
		free(table);
		exit(1);
	}
	table->num_eats = args.repeat;
	table->someone_die = 0;
	ft_init(table, args);
	do_routine(table);
}
