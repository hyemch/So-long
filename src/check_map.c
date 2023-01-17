/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:36:41 by hyecheon          #+#    #+#             */
/*   Updated: 2023/01/18 07:39:52 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_extension(char *filename)
{
	int	i;

	i = 0;
	while (filename && filename[i] != '\0')
		i++;
	if (filename[i - 4] != '.' || filename[i - 3] != 'b' || \
		filename[i - 2] != 'e' || filename[i - 1] != 'r')
		return (1);
	return (0);
}

void	check_map_components(t_map *map, t_game *game)
{
	int	i;

	i = 0;
	while (map->line[i])
	{
		if (map->line[i] == 'C')
			map->coll++;
		else if (map->line[i] == 'P')
		{
			map->player++;
			map->player_pos = i;
			game->p_pos = i;
		}
		else if (map->line[i] == 'E')
		{
			map->exit++;
			game->e_pos = i;
		}
		else if (map->line[i] != '0' && map->line[i] != '1')
			error_exit("Map component error!\n");
		i++;
	}
	if (map->coll < 1 || map->player != 1 || map->exit != 1)
		error_exit("Map component count error!\n");
}

void	check_map_rectangular(t_map *map)
{
	int	i;

	i = 0;
	map->line_len = (int)(ft_strlen(map->line));
	if (map->line_len != (map->width * map->height))
		error_exit("The map must be rectangular!\n");
	while (map->line[i])
	{
		if (i % map->width == 0 || i % map->width == map->width - 1 || \
		i < map->width || ((map->height - 1) * map->width <= i \
		&& i < map->height * map->width))
		{
			if (map->line[i] != '1')
				error_exit("Map wall error\n");
		}
		i++;
	}
}

void	check_map_route(t_map *map, int i)
{
	static int	coll_num;
	int			len;

	len = map->line_len;
	if (map->line[i] == 'C' || map->line[i] == 'E')
		coll_num++;
	if (coll_num == map->coll + 1)
	{
		map->valid++;
		return ;
	}
	if (map->line[i] == '1' || map->line[i] == 'a' \
		|| i < 0 || i >= len)
		return ;
	else
	{
		map->line[i] = 'a';
		check_map_route(map, i + 1);
		check_map_route(map, i + map->width);
		check_map_route(map, i - 1);
		check_map_route(map, i - map->width);
	}
}

void	check_map_valid(t_map *map, t_game *game)
{
	check_map_rectangular(map);
	check_map_components(map, game);
	check_map_route(map, map->player_pos);
	if (map->valid == 0)
		error_exit("Map route error!\n");
	else
		write(1, "HERE WE GO!\n", 12);
}
