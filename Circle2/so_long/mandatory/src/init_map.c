/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:33:50 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/10 12:11:15 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->moves = 0;
	init_map(&game->map);
	init_player(&game->player);
}

void	init_map(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->c_check = 0;
	map->e_check = 0;
	map->player_x = 0;
	map->player_y = 0;
}

void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
}

void	init_img(t_game *game)
{
	int	width;
	int	height;

	if (!game || !game->mlx)
		return ;
	width = IMG_PXL;
	height = IMG_PXL;
	game->image.img = mlx_xpm_file_to_image(game->mlx,
			"mandatory/xmp/ground.xmp", &width, &height);
	game->image.wall = mlx_xpm_file_to_image(game->mlx,
			"mandatory/xmp/wall.xmp", &width, &height);
	game->image.collect = mlx_xpm_file_to_image(game->mlx,
			"mandatory/xmp/collect.xmp", &width, &height);
	game->image.exit = mlx_xpm_file_to_image(game->mlx,
			"mandatory/xmp/door.xmp", &width, &height);
	game->image.player = mlx_xpm_file_to_image(game->mlx,
			"mandatory/xmp/player.xmp", &width, &height);
	if (!game->image.img || !game->image.wall || !game->image.collect
		|| !game->image.exit || !game->image.player)
	{
		ft_putstr_fd("Error: Failed to load one or more images\n", 2);
		ft_close_map(game);
		exit(1);
	}
}
