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

#include "../inc/so_long.h"

static void	draw_player(t_game *game, int x, int y)
{
	if (game->coll_cnt > 0)
		mlx_put_image_to_window(game->mlx, game->win, \
						game->img_player2, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
						game->img_player1, x, y);
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

int	draw_map(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (game->map[i] != '\0')
	{
		x = (i % game->mapinfo->width) * 64;
		y = (i / game->mapinfo->width) * 64;
		mlx_put_image_to_window(game->mlx, game->win, game->img_tile, x, y);
		if (game->map[i] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x, y);
		else if (i == game->p_pos)
			draw_player(game, x, y);
		else if (game->map[i] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->img_coll, x, y);
		else if (game->map[i] == 'E')
			draw_exit(game, x, y);
		i++;
	}
	return (0);
}
