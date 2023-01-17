/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:34:51 by hyecheon          #+#    #+#             */
/*   Updated: 2023/01/16 21:48:40 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	draw_player(t_game *game, int x, int y, unsigned int cnt)
{
	if (game->coll_cnt > 0)
	{
		if ((cnt % 30) < 15)
			mlx_put_image_to_window(game->mlx, game->win, \
						game->img_player2, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, \
									game->img_player3, x, y);
	}
	else
	{
		if ((cnt % 40) < 10)
			mlx_put_image_to_window(game->mlx, game->win, \
						game->img_player1, x, y);
		else if (10 <= (cnt % 40) && (cnt % 40) < 20)
			mlx_put_image_to_window(game->mlx, game->win, \
									game->img_player4, x, y);
		else if (20 <= (cnt % 40) && (cnt % 40) < 30)
			mlx_put_image_to_window(game->mlx, game->win, \
									game->img_player5, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, \
									game->img_player6, x, y);
	}
}

static void	draw_enemy(t_game *game, int x, int y, unsigned int cnt)
{
	if ((cnt % 30) < 15)
		mlx_put_image_to_window(game->mlx, game->win, game->img_enemy1, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_enemy2, x, y);
}

static void	draw_exit(t_game *game, int x, int y)
{
	if (game->coll_cnt == game->mapinfo->coll)
		mlx_put_image_to_window(game->mlx, game->win, \
				game->img_exit2, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
						game->img_exit1, x, y);
}

void	window_cnt(t_game *game)
{
	game->tmp = ft_itoa(game->move_cnt);
	mlx_string_put(game->mlx, game->win, 8, 66, 0xFF99FF, "move:");
	mlx_string_put(game->mlx, game->win, 45, 66, 0xFF99FF, game->tmp);
	free(game->tmp);
}

int	draw_map(t_game *game)
{
	int					i;
	int					x;
	int					y;
	static unsigned int	cnt;

	i = -1;
	cnt++;
	while (game->map[++i] != '\0')
	{
		x = (i % game->mapinfo->width) * 64;
		y = (i / game->mapinfo->width) * 64;
		mlx_put_image_to_window(game->mlx, game->win, game->img_tile, x, y);
		if (game->map[i] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x, y);
		else if (i == game->p_pos)
			draw_player(game, x, y, cnt);
		else if (game->map[i] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->img_coll, x, y);
		else if (game->map[i] == 'E')
			draw_exit(game, x, y);
		else if (i == game->e_pos)
			draw_enemy(game, x, y, cnt);
	}
	window_cnt(game);
	return (0);
}
