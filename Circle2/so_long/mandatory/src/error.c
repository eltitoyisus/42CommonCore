/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:33:45 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/02 12:33:45 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map && map->map)
	{
		while (i < map->rows && map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
}

void	destroy_img(void *mlx, void *img)
{
	if (mlx && img)
	{
		mlx_destroy_image(mlx, img);
		img = NULL;
	}
}
