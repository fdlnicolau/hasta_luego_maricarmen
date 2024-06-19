/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 04:16:02 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/26 04:16:02 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	parsing(t_game *game, char *argv)
{
	char	**visit;
	int		i;
	int		j;

	i = 0;
	j = 0;
	game->wth = (ft_strlen(game->map[0]) - 1);
	(void)argv;
	visit = NULL;
	check_components(game);
	visit = malloc(game->hgt * sizeof(char *));
	if (visit == NULL)
		ft_error("Error in valid malloc");
	check_walls(game, i, j);
	visit = duplicate_map(game, game->map);
	flood_fill(game);
	check_collectibles(game, (int **)visit);
}

char	**duplicate_map(t_game *game, char **original_map)
{
	int		i;
	char	**new_map;
	int		j;

	new_map = original_map;
	i = 0;
	while (i < game->hgt)
	{
		new_map[i] = malloc(game->wth * sizeof(char));
		if (new_map[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(new_map[j]);
				j++;
			}
			free(new_map);
			return (NULL);
		}
		memcpy(new_map[i], original_map[i], game->wth);
		i++;
	}
	return (new_map);
}

void	check_walls(t_game *game, int i, int j)
{
	while (j < game->wth - 1)
	{
		if (game->map[0][j] != '1')
			ft_error("Top wall check failed");
		j++;
	}
	j = 0;
	while (j < game->wth - 1)
	{
		if (game->map[game->hgt - 1][j] != '1')
			ft_error("Bottom wall check failed");
		j++;
	}
	while (i < game->hgt)
	{
		if (game->map[i][0] != '1')
			ft_error("Left wall check failed");
		j = game->wth - 1;
		if (game->map[i][j] != '1')
			ft_error("Right wall check failed");
		i++;
	}
}

void	check_components(t_game *game)
{
	int		i;
	int		j;
	char	*valid_chars;

	valid_chars = "10CEP\r\n";
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] != '\0'
			&& ft_strchr(valid_chars, game->map[i][j]) == NULL)
				ft_error("invalid character in map");
			j++;
		}
		i++;
	}
	if (count_comp(game->map, 'P') != 1)
		ft_error("Ocurrió un error con el jugador");
	if (count_comp(game->map, 'E') != 1)
		ft_error("Ocurrió un error con la salida");
	if (count_comp(game->map, 'C') == 0)
		ft_error("Ocurrió un error con los colectables");
}

void	check_rect_map(t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(game->map[0]);
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
			j++;
		if (j != len)
			ft_error("Bad line length");
		i++;
	}
	if (i < 3)
		ft_error("Map too small");
	game->wth = len;
	game->hgt = i;
}
