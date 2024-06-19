/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:12:42 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/25 17:12:42 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define S 64
# define EXTENSION_NO_BER -1
# define END_OF_PROGRAM -2
# define MAP_NOT_CORRECT -3

typedef struct s_game
{
	char				**map;
	int					players;
	int					exit;
	int					collectibles;
	int					hgt;
	int					wth;
	void				*window;
	int					player_x;
	int					player_y;
	mlx_texture_t		*floor_tex;
	mlx_texture_t		*wall_tex;
	mlx_texture_t		*collectible_tex;
	mlx_texture_t		*player_tex;
	mlx_texture_t		*exit_tex;
	mlx_texture_t		*collect_text;
	mlx_image_t			*floor_img;
	mlx_image_t			*exit_img;
	mlx_image_t			*p_img;
	mlx_image_t			*wall_img;
	mlx_image_t			*c_img;
	int					player_ps[2];
	mlx_t				*mlx;
	mlx_texture_t		*collect_tex;
	int					steps;
	mlx_image_t			*str;
	char				*temp;
	int					player_exit;
	int					total_collect;
}	t_game;

char	*reading(t_game *game, char *line, int wth, int fd);
char	*init_reading(int fd, t_game *game);
void	ft_pain_colect(t_game *g);
void	pos_player(t_game *g);
void	free_map(char **map);
int		flood_fill(t_game *game);
char	**duplicate_map(t_game *game, char **original_map);
void	ft_delete(t_game *g);
void	ft_exit_free(int nb_error, t_game *game);
void	ft_where_is(t_game *g);
void	close_window(t_game *game);
void	right_left_key(mlx_key_data_t keydata, t_game *g);
void	up_down_key(mlx_key_data_t keydata, t_game *g);
void	ft_clean_image(t_game *game);
void	init_key_hook(mlx_key_data_t keydata, void *game);
void	game_init(t_game *game);
void	texture_to_img(t_game *game);
void	load_png(t_game *game);
void	img_to_window(t_game *game);
void	game_control(t_game *game);
void	ft_error(const char *str);
void	free_game(t_game *game);
void	game_init2(t_game *game);
t_game	*game_memory_init(t_game **game);
void	preparation_map(t_game *game);
void	check_map_content(t_game *game, char cell, int i, int j);
void	copy_line(t_game *game, char *line, int i);
void	check_status(t_game *game);
void	check_map(char *str, t_game *game);
void	read_map(t_game *game, char *str);
void	check_walls(t_game *game, int i, int j);
void	check_components(t_game *game);
void	check_rect_map(t_game *game);
int		**init_visit(int hgt, int wth);
int		count_comp(char **map, char c);
void	parsing(t_game *game, char *argv);
int		map_size(int fd);
void	check_collectibles(t_game *game, int **visit);

#endif