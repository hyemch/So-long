/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:29:28 by hyecheon          #+#    #+#             */
/*   Updated: 2023/01/16 21:31:36 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb % 10 + '0');
}

void	move_player(int move, t_game *game)
{
	if (game->map[game->p_pos + move] == '1')
		return ;
	if (game->map[game->p_pos + move] == 'C')
		game->coll_cnt++;
	if (game->map[game->p_pos + move] == 'E' \
		&& game->coll_cnt == game->mapinfo->coll)
		clear_game(game);
	if (game->map[game->p_pos] != 'E')
		game->map[game->p_pos] = '0';
	game->p_pos += move;
	game->move_cnt++;
	write(1, "move : ", 7);
	ft_putnbr(game->move_cnt);
	write(1, "\n", 1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W)
	{
		game->move = -game->mapinfo->width;
		move_player(game->move, game);
	}
	else if (keycode == KEY_A)
	{
		game->move = -1;
		move_player(game->move, game);
	}
	else if (keycode == KEY_S)
	{
		game->move = +game->mapinfo->width;
		move_player(game->move, game);
	}
	else if (keycode == KEY_D)
	{
		game->move = +1;
		move_player(game->move, game);
	}
	return (0);
}
