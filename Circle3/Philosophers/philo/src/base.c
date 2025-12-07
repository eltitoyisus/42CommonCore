/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:47:59 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/24 09:06:25 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	base_philo(long number_philo, long time_to_die,
	long time_to_eat, long time_to_sleep)
{
	t_table			*table;
	t_philo_args	args;

	table = malloc_prevent(sizeof(t_table));
	if (!table)
		return ;
	args.number_philo = number_philo;
	args.time_to_die = time_to_die;
	args.time_to_eat = time_to_eat;
	args.time_to_sleep = time_to_sleep;
	args.repeat = -1;
	if (args.number_philo <= 0 || args.time_to_die <= 0
		|| args.time_to_eat <= 0 || args.time_to_sleep <= 0)
	{
		printf("Invalid input: all arguments must be positive numbers\n");
		free(table);
		exit(1);
	}
	ft_init(table, args);
	do_routine(table);
}
