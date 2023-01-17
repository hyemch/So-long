/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:33:31 by hyecheon          #+#    #+#             */
/*   Updated: 2023/01/16 21:40:47 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	error_exit(char *error_message)
{
	write(2, "Error\n", 6);
	write(2, error_message, ft_strlen(error_message));
	exit(1);
}

int	clear_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	write(1, "GAME CLEAR!\n", 12);
	exit(0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	write(1, "GAME OVER\n", 10);
	exit(0);
}

void	img_player(t_game *game, int *w, int *h)
{
	game->img_player1 = mlx_xpm_file_to_image(game->mlx, \
			"./textures/player1.xpm", w, h);
	game->img_player2 = mlx_xpm_file_to_image(game->mlx, \
			"./textures/player2.xpm", w, h);
	game->img_player3 = mlx_xpm_file_to_image(game->mlx, \
			"./textures/player3.xpm", w, h);
	game->img_player4 = mlx_xpm_file_to_image(game->mlx, \
			"./textures/player4.xpm", w, h);
	game->img_player5 = mlx_xpm_file_to_image(game->mlx, \
			"./textures/player5.xpm", w, h);
	game->img_player6 = mlx_xpm_file_to_image(game->mlx, \
			"./textures/player6.xpm", w, h);
}

void	init_mlx(t_map *map, t_game *game)
{
	int	w;
	int	h;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, \
			map->width * 64, map->height * 64, "so_long");
	game->img_tile = mlx_xpm_file_to_image(game->mlx, "./textures/tile.xpm", \
			&w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", \
			&w, &h);
	img_player(game, &w, &h);
	game->img_coll = mlx_xpm_file_to_image(game->mlx, \
			"./textures/coll1.xpm", &w, &h);
	game->img_exit1 = mlx_xpm_file_to_image(game->mlx, \
			"./textures/exit1.xpm", &w, &h);
	game->img_exit2 = mlx_xpm_file_to_image(game->mlx, \
			"./textures/exit2.xpm", &w, &h);
	game->img_enemy1 = mlx_xpm_file_to_image(game->mlx, \
			"./textures/enemy1.xpm", &w, &h);
	game->img_enemy2 = mlx_xpm_file_to_image(game->mlx, \
			"./textures/enemy2.xpm", &w, &h);
}
