/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:13:46 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/10 22:13:46 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	surrounded_by_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->cols)
	{
		if (map->map[0][i] != '1' || map->map[map->rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->map[i][0] != '1' || map->map[i][map->cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
