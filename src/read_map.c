/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:40:53 by hyecheon          #+#    #+#             */
/*   Updated: 2023/01/16 21:41:38 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_strnjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	ft_memset(str, 0, ft_strlen(s1) + ft_strlen(s2) + 1);
	i = -1;
	j = 0;
	while (s1[++i] && s1[i] != '\n')
		str[i] = s1[i];
	while (s2[j] != '\0' && s2[j] != '\n')
		str[i++] = s2[j++];
	str[i] = '\0';
	if (s1 != NULL)
	{
		free (s1);
		s1 = NULL;
	}
	return (str);
}

void	read_map(const char *map_file, t_map *map, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(map_file, O_RDONLY);
	if (fd <= 0)
		error_exit("Failed to open file\n");
	line = get_next_line(fd);
	if (!line)
		error_exit("malloc error\n");
	map->width = ft_strlen(line) - 1;
	tmp = 0;
	while (line)
	{
		tmp = ft_strnjoin(tmp, line);
		if (!tmp)
			error_exit("malloc error\n");
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map->line = tmp;
	game->map = ft_strnjoin(game->map, map->line);
	close(fd);
}
