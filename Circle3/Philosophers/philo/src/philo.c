/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:32:01 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/28 14:10:51 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo_args	args;

	if (argc == 5)
	{
		base_philo(ft_atol(argv[1]), ft_atol(argv[2]),
			ft_atol(argv[3]), ft_atol(argv[4]));
	}
	else if (argc == 6)
	{
		args.number_philo = ft_atol(argv[1]);
		args.time_to_die = ft_atol(argv[2]);
		args.time_to_eat = ft_atol(argv[3]);
		args.time_to_sleep = ft_atol(argv[4]);
		args.repeat = ft_atol(argv[5]);
		adv_philo(args);
	}
	else
	{
		printf("Usage: ./philo <philos> <time to die> <time to eat> ");
		printf("<time to sleep> <optional: repeat number of meals>\n");
	}
}
