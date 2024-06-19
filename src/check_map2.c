/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:02:51 by lnicolau          #+#    #+#             */
/*   Updated: 2024/06/19 20:02:51 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*init_reading(int fd, t_game *game)
{
	char	*line;
	int		wth;

	wth = 0;
	line = get_next_line(fd);
	if (line == NULL)
		ft_error("Empty file");
	reading(game, line, wth, fd);
	return(NULL);
}

char	*reading(t_game *game, char *line, int wth, int fd)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (line)
	{
		copy_line(game, line, i);
		j = 0;
		wth = ft_strlen(line);
		while (j < wth)
		{
			check_map_content(game, game->map[i][j], i, j);
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	check_status(game);
	return (NULL);
}

void	check_map_content(t_game *game, char cell, int i, int j)
{
	if (cell == 'P')
	{
		if (game->players == 0)
		{
			game->player_x = j;
			game->player_y = i;
			game->players = 1;
		}
		else
			ft_error("Multiple players found");
	}
	else if (cell == 'C')
	{
		game->collectibles += 1;
		game->total_collect += 1;
	}
	else if (cell == 'E')
	{
		if (game->exit == 0)
			game->exit = 1;
		else
			ft_error("Multiple exits found");
	}
	else if (cell != '1' && cell != '0' && cell != '\n' && cell != '\0')
		ft_error("Unexpected cell character");
}
