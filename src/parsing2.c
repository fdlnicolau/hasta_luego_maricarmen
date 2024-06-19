/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:39:56 by lnicolau          #+#    #+#             */
/*   Updated: 2024/06/19 23:50:54 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_collectibles(t_game *game, int **visit)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->hgt)
	{
		j = 0;
		while (j < game->wth)
		{
			if (game->map[i][j] == 'C' && visit[i][j] == 1)
			{
				game->collectibles--;
			}
			j++;
		}
		i++;
	}
}

int	**init_visit(int hgt, int wth)
{
	int	i;
	int	**visit;

	i = 0;
	visit = (int **)malloc(sizeof(int *) * hgt);
	if (visit == NULL)
		ft_error("error");
	while (i < hgt)
	{
		visit[i] = (int *)malloc(sizeof(int) * wth);
		if (visit[i] == NULL)
			ft_error("error");
		i++;
	}
	return (visit);
}

char	*fill(char **map, int rows, int columns)
{
	map[rows][columns] = '1';
	if (map[rows - 1][columns] != '1')
		fill(map, (rows - 1), columns);
	if (map[rows + 1][columns] != '1')
		fill(map, (rows + 1), columns);
	if (map[rows][columns - 1] != '1')
		fill(map, rows, (columns -1));
	if (map[rows][columns + 1] != '1')
		fill(map, rows, (columns + 1));
	return (*map);
}

int	part_floodfill(char	**copymap)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (copymap[c] && copymap[c][r] != '\0')
	{
		r = 0;
		while (copymap[c][r] != '\n')
		{
			if (copymap[c][r] == 'C' || copymap[c][r] == 'E')
			{
				free_map(copymap);
				ft_error("Error in map file.");
			}
			r++;
		}
		c++;
	}
	free_map(copymap);
	return (1);
}

int	flood_fill(t_game *game)
{
	char	**copymap;
	int		i;

	i = 0;
	pos_player(game);
	copymap = malloc(sizeof(char *) * game->hgt + 1);
	while (i < game->hgt)
	{
		copymap[i] = ft_strdup(game->map[i]);
		i++;
	}
	copymap[i] = NULL;
	fill(copymap, game->player_y, game->player_x);
	part_floodfill(copymap);
	return (1);
}
