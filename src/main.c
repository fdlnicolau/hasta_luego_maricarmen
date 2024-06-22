/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:40:29 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/20 15:40:29 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game);
	if (argc == 2 && argv)
	{
		check_map(argv[1], &game);
		game_control(&game);
	}
	ft_exit_free(END_OF_PROGRAM, &game);
	return (EXIT_SUCCESS);
}

t_game	*game_memory_init(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (*game == NULL)
		ft_error("Failed to allocate memory for the game");
	(*game)->map = NULL;
	return (*game);
}

void	check_map(char *str, t_game *game)
{
	char	*final;

	final = ft_strdup (str + ft_strlen(str) - 4);
	if (final == NULL)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(final, ".ber", 4))
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		free(final);
		exit(EXIT_FAILURE);
	}
	read_map(game, str);
	free(final);
}

void	game_control(t_game *game)
{
	game->mlx = mlx_init((game->wth) * S, game->hgt * S, "so_long", false);
	if (game->mlx == NULL)
		ft_error("mlx_init failed");
	load_png(game);
	texture_to_img(game);
	img_to_window(game);
	mlx_image_to_window(game->mlx, game->p_img,
		game->player_ps[0] * S, game->player_ps[1] * S);
	mlx_key_hook(game->mlx, &init_key_hook, game);
	mlx_loop(game->mlx);
}
