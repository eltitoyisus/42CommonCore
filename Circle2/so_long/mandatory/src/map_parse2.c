/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:05:26 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/10 19:05:26 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_dimensions(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		row;
	int		line_len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	row = 0;
	map->cols = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_len = ft_strlen(line);
		if (line[line_len - 1] == '\n')
			line_len--;
		if (line_len > map->cols)
			map->cols = line_len;
		free(line);
		row++;
		line = get_next_line(fd);
	}
	map->rows = row;
	close(fd);
	return (1);
}

int	initialize_map_memory(t_map *map)
{
	map->map = (char **)malloc(sizeof(char *) * map->rows);
	if (!map->map)
		return (0);
	map->c = 0;
	map->e = 0;
	map->p = 0;
	return (1);
}

static void	count_map_elements(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'C')
			map->c++;
		else if (line[i] == 'E')
			map->e++;
		else if (line[i] == 'P')
			map->p++;
		i++;
	}
}

int	read_map_from_file(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		row;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	row = 0;
	while (row < map->rows && line)
	{
		map->map[row] = ft_strdup(line);
		count_map_elements(line, map);
		free(line);
		line = get_next_line(fd);
		row++;
	}
	close(fd);
	return (1);
}

int	load_map_from_file(char *filename, t_map *map)
{
	if (!get_map_dimensions(filename, map))
		return (0);
	if (!load_map_content(filename, map))
		return (0);
	return (1);
}
