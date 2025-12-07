/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:33:50 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/02 12:33:50 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (game->map.map[y][x] == '1')
				draw_wall(game);
			else if (game->map.map[y][x] == 'C')
				draw_collect(game);
			else if (game->map.map[y][x] == 'E')
				draw_exit(game);
			x++;
		}
		y++;
	}
}

static	void	draw_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->image.img, x * IMG_PXL, y * IMG_PXL);
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->image.wall, x * IMG_PXL, y * IMG_PXL);
	else if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->image.collect, x * IMG_PXL, y * IMG_PXL);
	else if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->image.exit, x * IMG_PXL, y * IMG_PXL);
	else if (game->map.map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->image.player, x * IMG_PXL, y * IMG_PXL);
}

int	draw_game(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->mlx || !game->win)
		return (1);
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
