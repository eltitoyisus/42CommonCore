/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:33:31 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/02 12:33:31 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(&filename[len - 4], ".ber", 4) == 0);
}

int	check_file(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (0);
	}
	if (!check_extension(argv[1]))
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		return (0);
	}
	if (!check_file(argv[1]))
	{
		ft_putstr_fd("Error\nInvalid file\n", 2);
		return (0);
	}
	return (1);
}
