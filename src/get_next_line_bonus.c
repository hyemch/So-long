/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:56:26 by hyecheon          #+#    #+#             */
/*   Updated: 2022/10/19 15:59:43 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static char	*next_line(char *keep)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (keep[i] != '\n' && keep[i] != '\0')
		i++;
	if (keep[i] == '\0')
	{
		free (keep);
		keep = NULL;
		return (0);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(keep) - i));
	if (!temp)
		return (0);
	i++;
	while (keep[i] != '\0')
		temp[j++] = keep[i++];
	temp[j] = '\0';
	ft_memset(keep, 0, ft_strlen(keep));
	free(keep);
	keep = NULL;
	return (temp);
}

static char	*get_line(char *keep)
{
	char	*temp;
	int		i;

	i = 0;
	if (keep[i] == 0)
		return (0);
	while (keep[i] != '\n' && keep[i] != '\0')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (0);
	i = 0;
	while (keep[i] != '\n' && keep[i] != '\0')
	{
		temp[i] = keep[i];
		i++;
	}
	if (keep[i] == '\n')
	{
		temp[i] = keep[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

static char	*read_line(int fd, char *keep)
{
	char	*buff;
	int		ret;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret < 0)
	{
		free(buff);
		free(keep);
		return (0);
	}
	while (ret > 0)
	{
		keep = ft_strjoin(keep, buff);
		if (ft_strchr(keep, '\n'))
			break ;
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		ret = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	buff = NULL;
	return (keep);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*keep;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	keep = read_line(fd, keep);
	if (!keep)
		return (0);
	line = get_line(keep);
	if (!line)
	{
		free (line);
		line = NULL;
	}
	keep = next_line(keep);
	if (!keep)
	{
		free(keep);
		keep = NULL;
	}
	return (line);
}
