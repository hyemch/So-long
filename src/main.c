/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:23:43 by hyecheon          #+#    #+#             */
/*   Updated: 2023/01/17 16:30:26 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
		return (write(2, "ERROR\nArgument count error\n", 27));
	if (map_extension(argv[1]) == 1)
		return (write(2, "Map extension error\n", 20));
	ft_memset(&map, 0, sizeof(map));
	ft_memset(&game, 0, sizeof(game));
	read_map(argv[1], &map, &game);
	check_map_valid(&map, &game);
	game.mapinfo = &map;
	init_mlx(&map, &game);
	mlx_loop_hook(game.mlx, draw_map, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, key_hook, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
