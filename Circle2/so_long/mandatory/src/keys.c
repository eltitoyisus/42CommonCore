/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:33:08 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/02 12:33:08 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->player.x;
	prev_y = game->player.y;
	if (keycode == KEY_W)
		move_w(game);
	else if (keycode == KEY_A)
		move_a(game);
	else if (keycode == KEY_S)
		move_s(game);
	else if (keycode == KEY_D)
		move_d(game);
	else if (keycode == KEY_ESC)
		ft_close_map(game);
	if (game->player.x != prev_x || game->player.y != prev_y)
	{
		game->moves++;
		ft_putstr_fd("Movimientos: ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}
