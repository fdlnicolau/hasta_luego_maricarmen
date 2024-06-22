/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:12:29 by lnicolau          #+#    #+#             */
/*   Updated: 2024/06/10 20:01:39 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = (t_game *) param;
	ft_where_is(g);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit_free(END_OF_PROGRAM, g);
	up_down_key(keydata, g);
	right_left_key(keydata, g);
	mlx_delete_image(g->mlx, g->str);
	g->temp = ft_itoa(g->steps);
	g->str = mlx_put_string(g->mlx, g->temp, g->wth * S - 32, g->hgt * S - 20);
	free(g->temp);
}

void	ft_where_is(t_game *g)
{
	if (g->map[g->player_ps[1]][g->player_ps[0]] == 'C')
		handle_collectible(g);
	if (g->exit_img->instances[0].y / S == g->p_img->instances->y / S
		&& g->exit_img->instances[0].x / S == g->p_img->instances->x / S
		&& g->exit_img->instances[0].enabled == true && g->collectibles == 0)
		ft_exit_free(END_OF_PROGRAM, g);
}

void	handle_collectible(t_game *g)
{
	int	i;

	if (g->map[g->player_ps[1]][g->player_ps[0]] == 'C')
	{
		g->map[g->player_ps[1]][g->player_ps[0]] = 'P';
		i = 0;
		while (i < g->total_collect)
		{
			if (g->c_img->instances[i].y / S == g->p_img->instances->y / S
				&& g->c_img->instances[i].x / S == g->p_img->instances->x / S
				&& g->c_img->instances[i].enabled == true)
			{
				g->collectibles--;
				g->c_img->instances[i].enabled = false;
				g->map[g->c_img->instances[i].y / S]
				[g->c_img->instances[i].x / S] = '0';
			}
			i++;
		}
	}
}

void	up_down_key(mlx_key_data_t keydata, t_game *g)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit_free(EXIT_SUCCESS, g);
	if (g->map[g->player_ps[1] - 1][g->player_ps[0]] != '1')
	{
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		{
			g->p_img->instances[0].y -= S;
			g->player_ps[1]--;
			g->steps++;
			ft_printf("Steps: %d\n", g->steps);
		}
	}
	if (g->map[g->player_ps[1] + 1][g->player_ps[0]] != '1')
	{
		if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		{
			g->p_img->instances[0].y += S;
			g->player_ps[1]++;
			g->steps++;
			ft_printf("Steps: %d\n", g->steps);
		}
	}
}

void	right_left_key(mlx_key_data_t keydata, t_game *g)
{
	if (g->map[g->player_ps[1]][g->player_ps[0] - 1] != '1')
	{
		if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		{
			g->p_img->instances[0].x -= S;
			g->player_ps[0]--;
			g->steps++;
			ft_printf("Steps: %d\n", g->steps);
		}
	}
	if (g->map[g->player_ps[1]][g->player_ps[0] + 1] != '1')
	{
		if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		{
			g->p_img->instances[0].x += S;
			g->player_ps[0]++;
			g->steps++;
			ft_printf("Steps: %d\n", g->steps);
		}
	}
}
