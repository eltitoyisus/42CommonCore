/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:21:50 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/02 15:21:50 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/struct.h"

void	valid_args(t_table *table, char **argv)
{
	table->num_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (table->num_philos <= 0 || table->time_to_die <= 0
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0)
	{
		printf("Invalid input: all arguments must be positive numbers\n");
		exit(1);
	}
	if (table->num_philos > 100)
		printf("cant use more than 100 philosophers");
	if (table->time_to_die < 200
		|| table->time_to_eat < 200
		|| table->time_to_sleep < 200)
		printf("Use bigger time stamps");
}
