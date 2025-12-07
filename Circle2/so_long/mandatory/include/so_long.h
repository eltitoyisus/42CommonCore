/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:33:40 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/11 09:03:07 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/libft.h"
# include "../../minilibx/mlx.h"
# include "../../minilibx/mlx_int.h"
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define IMG_PXL 64
# define WND_NAME "so_long"

typedef struct s_map
{
	char	**map;
	char	**copy;
	int		rows;
	int		cols;
	int		c;
	int		e;
	int		p;
	int		c_check;
	int		e_check;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_image
{
	void	*img;
	void	*empty;
	void	*wall;
	void	*exit;
	void	*collect;
	void	*player;
	int		width;
	int		height;
}	t_image;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_image		image;
	t_player	player;
	int			screen_width;
	int			screen_height;
	int			moves;
}	t_game;

// MAP PARSE
char	**copy_map(char **map, int rows);
void	find_player(t_map *map);
void	move_on_paths(int x, int y, t_map *map);
int		check_valid_path(t_map *map);
int		ft_parse_map(int argc, char **argv, t_map *map);

// KEYS
int		key_hook(int keycode, t_game *game);

// MOVEMENT
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	move_w(t_game *game);

// INIT MAP
void	init_game(t_game *game);
void	init_map(t_map *map);
void	init_player(t_player *player);
void	init_img(t_game *game);

// DRAW MAP
void	draw_map(t_game *game);
void	draw_player(t_game *game);
void	draw_collect(t_game *game);
void	draw_exit(t_game *game);
void	draw_background(t_game *game);
int		draw_game(t_game *game);
void	draw_wall(t_game *game);

// END MAP
int		ft_close_map(t_game *game);

// ERROR AND FREE
void	ft_free_map(t_map *map);
void	free_game(t_game *game);

// MAP NAME PARSE

int		check_extension(char *filename);
int		check_args(int argc, char **argv);
int		check_file(char *file);

// IS PLAYABLE
void	free_img(void *mlx, t_image *image);
void	destroy_img(void *mlx, void *img);
int		get_map_dimensions(char *filename, t_map *map);
int		initialize_map_memory(t_map *map);
int		read_map_from_file(char *filename, t_map *map);
int		load_map_content(char *filename, t_map *map);
int		load_map_from_file(char *filename, t_map *map);
int		no_collectibles(t_map *map);
int		one_exit(t_map *map);
int		one_player(t_map *map);
int		check_map(t_map *map);
int		surrounded_by_walls(t_map *map);


#endif