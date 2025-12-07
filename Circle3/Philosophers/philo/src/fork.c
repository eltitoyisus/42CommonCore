/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:44:06 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/11 07:44:06 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	is_even(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(&philo->table->death_mutex);
	if (!philo->table->someone_die)
		printf("%ld %ld has taken a fork\n",
			get_current_time() - philo->table->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->death_mutex);
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(&philo->table->death_mutex);
	if (!philo->table->someone_die)
		printf("%ld %ld has taken a fork\n",
			get_current_time() - philo->table->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->death_mutex);
}

void	is_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(&philo->table->death_mutex);
	if (!philo->table->someone_die)
		printf("%ld %ld has taken a fork\n",
			get_current_time() - philo->table->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->death_mutex);
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(&philo->table->death_mutex);
	if (!philo->table->someone_die)
		printf("%ld %ld has taken a fork\n",
			get_current_time() - philo->table->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->death_mutex);
}
