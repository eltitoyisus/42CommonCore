/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:48:21 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/11 08:18:57 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "headers.h"
# include "struct.h"

// UTILS
long	ft_atol(char *str);
void	*malloc_prevent(size_t bytes);

// TIME CONTROL
size_t	get_current_time(void);
int		ft_usleep(size_t m);

// PARSE
void	valid_args(t_table *table, char **argv);

// DO PHILO
void	do_routine(t_table *table);
void	base_philo(long number_philo, long time_to_die,
			long time_to_eat, long time_to_sleep);
void	adv_philo(t_philo_args args);

// DO MUTEX
void	mutex_init(t_table *table);
void	mutex_destroy(t_table *table);
void	free_philo(t_table *table);

// DO THREAD
void	create_thread(t_table *table);
void	join_thread(t_table *table);

// ROUTINE
void	*routine(void *arg);
void	x_routine(t_philo *philo);
void	*monitor_routine(void *arg);
void	is_even(t_philo *philo);
void	is_odd(t_philo *philo);
void	ft_init(t_table *table, t_philo_args args);
int		one_philo(t_philo *philo);
int		die(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	take_fork(t_philo *philo);
void	handle_philo_death(t_table *table, int i, size_t current_time);
int		check_philo_state(t_table *table, int i, int *all_ate_enough);
int		monitor_philos(t_table *table);

#endif
