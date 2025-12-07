/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:33:48 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/10 12:05:13 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	int	initialize_game(t_game *game, int argc, char **argv)
{
	ft_memset(game, 0, sizeof(t_game));
	init_game(game);
	if (ft_parse_map(argc, argv, &game->map) != 0)
	{
		ft_putstr_fd("Error: Map parsing failed\n", 2);
		return (1);
	}
	game->mlx = mlx_init();
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	if (game->map.cols * IMG_PXL > game->screen_width
		|| game->map.rows * IMG_PXL > game->screen_height)
	{
		ft_putstr_fd("Error: Map too large for screen\n", 2);
		ft_close_map(game);
		return (1);
	}
	return (0);
}

static	int	setup_and_run_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map.cols * IMG_PXL,
			game->map.rows * IMG_PXL, WND_NAME);
	if (!game->win)
	{
		ft_putstr_fd("Error: Window creation failed\n", 2);
		return (1);
	}
	init_img(game);
	game->player.x = game->map.player_x;
	game->player.y = game->map.player_y;
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 1L << 17, ft_close_map, game);
	mlx_loop_hook(game->mlx, draw_game, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (initialize_game(&game, argc, argv) == 0)
		setup_and_run_game(&game);
	free_game(&game);
	ft_free_map(&game.map);
	return (0);
}
