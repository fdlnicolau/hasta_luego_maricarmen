/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 04:50:41 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/26 04:50:41 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_comp(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void pos_player(t_game *g)
{
	if (g->map[g->player_ps[1]][g->player_ps[0]] == 'C')
	{
		g->map[g->player_ps[1]][g->player_ps[0]] = 'P';
		ft_pain_colect(g);
		if (g->p_img)
    	{
        	mlx_delete_image(g->mlx, g->p_img);
        	g->p_img = NULL;
    	}
		g->p_img = mlx_texture_to_image(g->mlx, g->player_tex);
		mlx_image_to_window(g->mlx, g->p_img,
			g->player_ps[0] * S, g->player_ps[1] * S);
	}
	else if (g->map[g->player_ps[1]][g->player_ps[0]] == 'E' && !g->player_exit)
		ft_exit_free(EXIT_SUCCESS, g);
}

void	ft_pain_colect(t_game *g)
{
	int	i;
	int	j;
	int	count;
	int index;

	count = 0;
	i = -1;
	index = 0;
	ft_delete(g);
	while (++i <= g->hgt - 1)
	{
		j = -1;
		while (++j <= g->wth - 1)
		{
			if (g->map[i][j] == 'C' && g->c_img->instances[index].enabled == true)
			{
				count++;
				mlx_image_to_window(g->mlx, g->c_img, j * S, i * S);
				index++;
			}
		}
	}
}

void   ft_delete(t_game *g)
{
	int i;

	int counter;
	i = 0;
	counter = g->collectibles;
	while (i < counter)
	{
		if((g->c_img->instances[i].y == g->p_img->instances->y)
			&& (g->c_img->instances[i].x == g->p_img->instances->x)
			&& (g->c_img->instances[i].enabled == true))
		{
			g->c_img->instances[i].enabled = false;
			counter --;
		}
		i++;
	}
}
