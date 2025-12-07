/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:28:47 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/10 19:28:47 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	load_map_content(char *filename, t_map *map)
{
	if (!initialize_map_memory(map))
		return (0);
	if (!read_map_from_file(filename, map))
		return (0);
	return (1);
}

int	no_collectibles(t_map *map)
{
	int	i;
	int	j;
	int	collectibles;

	collectibles = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	if (collectibles == 0)
		return (0);
	return (1);
}

int	one_exit(t_map *map)
{
	int	i;
	int	j;
	int	exit;

	exit = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (0);
	return (1);
}

int	one_player(t_map *map)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (0);
	return (1);
}

int	check_map(t_map *map)
{
	if (!one_player(map))
		return (0);
	if (!one_exit(map))
		return (0);
	if (!no_collectibles(map))
	{
		ft_putstr_fd("No collectibles\n", 2);
		return (0);
	}
	if (!surrounded_by_walls(map))
	{
		ft_putstr_fd("Map not surrounded by walls\n", 2);
		return (0);
	}
	return (1);
}
