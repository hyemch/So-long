/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:36:35 by hyecheon          #+#    #+#             */
/*   Updated: 2023/01/18 00:36:58 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	set_enemy(t_map *map, t_game *game)
{
	int	i;

	i = 0;
	while (map->line[i] != '\0')
	{
		if (map->line[i] == 'a' && game->map[i] == '0')
		{
			game->e_pos = i;
			return ;
		}
		i++;
	}
}

void	move_enemy(int move, t_game *game)
{
	move *= -1;
	if (game->map[game->e_pos + move] != '0')
		return ;
	else
		game->e_pos += move;
}
