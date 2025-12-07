/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:33:36 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/10 12:11:45 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	xmp_convert(t_game *game)
{
	int	a;

	a = IMG_PXL;
	game->image.empty = mlx_xpm_file_to_image(game->mlx,
			"mandatory/xmp/ground.xmp", &a, &a);
	game->image.wall = mlx_xpm_file_to_image(game->mlx,
			"mandatory/xmp/wall.xmp", &a, &a);
	game->image.exit = mlx_xpm_file_to_image(game->mlx,
			"mandatory/xmp/door.xmp", &a, &a);
	game->image.collect = mlx_xpm_file_to_image(game->mlx,
			"mandatory/xmp/collect.xmp", &a, &a);
	game->image.player = mlx_xpm_file_to_image(game->mlx,
			"mandatory/xmp/player.xmp", &a, &a);
}
