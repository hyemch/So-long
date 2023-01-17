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

#include "../inc/so_long_bonus.h"

int	nbr_len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	else if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		len;

	nbr = n;
	len = nbr_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (nbr == 0)
		str[0] = 48;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[len] = 48 + (nbr % 10);
		nbr /= 10;
		len--;
	}
	return (str);
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
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W)
		game->move = -game->mapinfo->width;
	else if (keycode == KEY_A)
		game->move = -1;
	else if (keycode == KEY_S)
		game->move = +game->mapinfo->width;
	else if (keycode == KEY_D)
		game->move = +1;
	move_enemy(game->move, game);
	if (game->p_pos == game->e_pos || game->p_pos + game->move == game->e_pos)
	{
		write(1, "ENEMY!!", 7);
		exit_game(game);
	}
	move_player(game->move, game);
	return (0);
}
