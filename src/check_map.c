/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:04:14 by lnicolau          #+#    #+#             */
/*   Updated: 2024/06/10 20:02:01 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_size(int fd)
{
	char	*line;
	int		size;

	size = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	return (size);
}

void	read_map(t_game *game, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_error("Error opening file");
		exit(EXIT_FAILURE);
	}
	game->hgt = map_size(fd);
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_error("Error opening file");
		exit(EXIT_FAILURE);
	}
	preparation_map(game);
	init_reading(fd, game);
	close(fd);
	parsing(game, str);
}

void	check_status(t_game *game)
{
	if (!game->players)
		ft_error("Player not found");
	if (!game->exit)
		ft_error("Exit not found");
	if (game->collectibles == 0)
		ft_error("Collectibles not found");
}

void	copy_line(t_game *game, char *line, int i)
{
	int	len;
	int	j;

	j = 0;
	len = strlen(line);
	game->map[i] = malloc(sizeof(char) * (len + 1));
	if (!game->map[i])
	{
		perror("Failed to allocate memory for game->map[i]");
		exit(EXIT_FAILURE);
	}
	if (line[j] != '\0' && line[j] != '\n' && line[j] != '\r')
		strcpy(game->map[i], line);
	game->map[i][len] = '\0';
}

void	preparation_map(t_game *game)
{
	game->map = malloc(sizeof(char *) * (game->hgt + 1));
	if (!game->map)
	{
		perror("Failed to allocate memory for map");
		exit(EXIT_FAILURE);
	}
	ft_memset(game->map, 0, sizeof(char *) * (game->hgt + 1));
}
