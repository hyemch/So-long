/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:25:31 by hyecheon          #+#    #+#             */
/*   Updated: 2023/01/07 16:25:43 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <fcntl.h> //open
# include <stdarg.h> //ftprintf
# include <stdio.h> //perror
# include <stdlib.h> //exit, malloc, free
# include <string.h> //strerror
# include <unistd.h> //write, close, read

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_map
{
	int		player;
	int		player_pos;
	int		valid;
	int		coll;
	int		exit;
	int		width;
	int		height;
	int		line_len;
	char	*line;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_tile;
	void	*img_wall;
	void	*img_player1;
	void	*img_player2;
	void	*img_coll;
	void	*img_exit1;
	void	*img_exit2;
	char	*map;
	int		move;
	int		p_pos;
	int		e_pos;
	int		coll_cnt;
	int		move_cnt;
	t_map	*mapinfo;
}	t_game;

char	*ft_strnjoin(char *s1, char *s2);
void	read_map(const char *map_file, t_map *map, t_game *game);

int		map_extension(char *filename);
void	check_map_components(t_map *map, t_game *game);
void	check_map_rectangular(t_map *map);
void	check_map_route(t_map *map, int i);
void	check_map_valid(t_map *map, t_game *game);

void	init_mlx(t_map *map, t_game *game);
void	error_exit(char *error_message);
int		clear_game(t_game *game);
int		exit_game(t_game *game);

int		draw_map(t_game *game);

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	move_player(int move, t_game *game);
int		key_hook(int keycode, t_game *game);

#endif
