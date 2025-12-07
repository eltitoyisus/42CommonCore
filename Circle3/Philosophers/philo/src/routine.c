/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:59:15 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/13 10:24:30 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->someone_die)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return ;
	}
	printf("%ld %ld is sleeping\n",
		get_current_time() - philo->table->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->death_mutex);
	ft_usleep(philo->table->time_to_sleep);
}

void	think(t_philo *philo)
{
	long	think_time;

	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->someone_die)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return ;
	}
	printf("%ld %ld is thinking\n",
		get_current_time() - philo->table->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->death_mutex);
	if (philo->table->num_philos % 2 == 0)
		think_time = 1;
	else
		think_time = (philo->table->time_to_eat * 2
				- philo->table->time_to_sleep) / 2;
	if (think_time > 0)
		ft_usleep(think_time);
}

void	take_fork(t_philo *philo)
{
	if (die(philo))
		return ;
	if (philo->id % 2 == 0)
		is_even(philo);
	else
		is_odd(philo);
}

void	eat(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->someone_die)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return ;
	}
	philo->last_eat_time = get_current_time();
	philo->eat_count++;
	printf("%ld %ld is eating\n",
		get_current_time() - philo->table->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->death_mutex);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}
