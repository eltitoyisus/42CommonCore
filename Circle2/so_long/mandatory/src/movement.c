/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:35:22 by jramos-a          #+#    #+#             */
/*   Updated: 2025/01/30 13:35:22 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_a(t_game *game)
{
	if (game->map.map[game->map.player_y][game->map.player_x - 1] == 'E')
	{
		if (game->map.c == 0)
		{
			game->map.map[game->map.player_y][game->map.player_x] = '0';
			game->map.map[game->map.player_y][game->map.player_x - 1] = 'P';
			game->map.player_x--;
			game->map.e_check++;
			ft_putstr_fd("You win! All collectibles gathered.\n", 1);
			ft_close_map(game);
		}
	}
	else if (game->map.map[game->map.player_y][game->map.player_x - 1] == '0'
		|| game->map.map[game->map.player_y][game->map.player_x - 1] == 'C')
	{
		if (game->map.map[game->map.player_y][game->map.player_x - 1] == 'C')
			game->map.c--;
		game->map.map[game->map.player_y][game->map.player_x] = '0';
		game->map.map[game->map.player_y][game->map.player_x - 1] = 'P';
		game->map.player_x--;
	}
	game->player.x = game->map.player_x;
	game->player.y = game->map.player_y;
	draw_game(game);
}

void	move_s(t_game *game)
{
	if (game->map.map[game->map.player_y + 1][game->map.player_x] == 'E')
	{
		if (game->map.c == 0)
		{
			game->map.map[game->map.player_y][game->map.player_x] = '0';
			game->map.map[game->map.player_y + 1][game->map.player_x] = 'P';
			game->map.player_y++;
			game->map.e_check++;
			ft_putstr_fd("You win! All collectibles gathered.\n", 1);
			ft_close_map(game);
		}
	}
	else if (game->map.map[game->map.player_y + 1][game->map.player_x] == '0'
		|| game->map.map[game->map.player_y + 1][game->map.player_x] == 'C')
	{
		if (game->map.map[game->map.player_y + 1][game->map.player_x] == 'C')
			game->map.c--;
		game->map.map[game->map.player_y][game->map.player_x] = '0';
		game->map.map[game->map.player_y + 1][game->map.player_x] = 'P';
		game->map.player_y++;
	}
	game->player.x = game->map.player_x;
	game->player.y = game->map.player_y;
	draw_game(game);
}

void	move_d(t_game *game)
{
	if (game->map.map[game->map.player_y][game->map.player_x + 1] == 'E')
	{
		if (game->map.c == 0)
		{
			game->map.map[game->map.player_y][game->map.player_x] = '0';
			game->map.map[game->map.player_y][game->map.player_x + 1] = 'P';
			game->map.player_x++;
			game->map.e_check++;
			ft_putstr_fd("You win! All collectibles gathered.\n", 1);
			ft_close_map(game);
		}
	}
	else if (game->map.map[game->map.player_y][game->map.player_x + 1] == '0'
		|| game->map.map[game->map.player_y][game->map.player_x + 1] == 'C')
	{
		if (game->map.map[game->map.player_y][game->map.player_x + 1] == 'C')
			game->map.c--;
		game->map.map[game->map.player_y][game->map.player_x] = '0';
		game->map.map[game->map.player_y][game->map.player_x + 1] = 'P';
		game->map.player_x++;
	}
	game->player.x = game->map.player_x;
	game->player.y = game->map.player_y;
	draw_game(game);
}

void	move_w(t_game *game)
{
	if (game->map.map[game->map.player_y - 1][game->map.player_x] == 'E')
	{
		if (game->map.c == 0)
		{
			game->map.map[game->map.player_y][game->map.player_x] = '0';
			game->map.map[game->map.player_y - 1][game->map.player_x] = 'P';
			game->map.player_y--;
			game->map.e_check++;
			ft_putstr_fd("You win! All collectibles gathered.\n", 1);
			ft_close_map(game);
		}
	}
	else if (game->map.map[game->map.player_y - 1][game->map.player_x] == '0'
		|| game->map.map[game->map.player_y - 1][game->map.player_x] == 'C')
	{
		if (game->map.map[game->map.player_y - 1][game->map.player_x] == 'C')
			game->map.c--;
		game->map.map[game->map.player_y][game->map.player_x] = '0';
		game->map.map[game->map.player_y - 1][game->map.player_x] = 'P';
		game->map.player_y--;
	}
	game->player.x = game->map.player_x;
	game->player.y = game->map.player_y;
	draw_game(game);
}
