/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:33:25 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/02 12:33:25 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	destroy_all_images(void *mlx, t_image *image)
{
	if (mlx && image)
	{
		destroy_img(mlx, image->img);
		destroy_img(mlx, image->empty);
		destroy_img(mlx, image->wall);
		destroy_img(mlx, image->exit);
		destroy_img(mlx, image->collect);
		destroy_img(mlx, image->player);
	}
}

static	void	destroy_mlx_resources(void *mlx, void *win)
{
	if (mlx)
	{
		if (win)
			mlx_destroy_window(mlx, win);
		mlx_destroy_display(mlx);
		free(mlx);
	}
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx)
	{
		free_img(game->mlx, &game->image);
		destroy_mlx_resources(game->mlx, game->win);
	}
}

void	free_img(void *mlx, t_image *image)
{
	if (!mlx || !image)
		return ;
	destroy_all_images(mlx, image);
}

int	ft_close_map(t_game *game)
{
	ft_putstr_fd("Closing game\n", 1);
	free_game(game);
	ft_free_map(&game->map);
	exit(0);
	return (0);
}
